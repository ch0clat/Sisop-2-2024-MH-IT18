#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int num_pids = 0;

void open (const char *appName, int count, int state){
    for (int i = 0; i < count; i++){
        pid_t pid;
        pid = fork();
        if (pid == 0) {
            execlp(appName, appName, NULL); 
            fprintf(stderr, "Error : Failed to start %s\n", appName);
            exit(1);
        } else if (pid > 0) {
            FILE* log = fopen("setup.log", "a");
            fprintf(log, "%s %d %d\n", appName, pid, state);
            num_pids++;
            fclose(log);
        }
    }
}

void file_open (const char *filename, int state){
    FILE* config = fopen(filename, "r");

    if (config == NULL) {
        fprintf(stderr, "Error : Unable to open file\n");
        return;
    }

    char appName [255];
    int count;

    while (fscanf(config, "%s %d", appName, &count) == 2){
        open(appName, count, state);
    }
    
    fclose(config);

}

void stop (int state) {
    FILE* log = fopen("setup.log", "r");
    
    pid_t pid;
    int log_state;
    char appName [255];


    while (fscanf(log, "%s %d %d", appName, &pid, &log_state) == 3){
        if (state == 1) {
            if (log_state == state){
                if (kill(pid, SIGTERM) == -1) {
            printf("Error : Failed to send SIGTERM %d\n", pid);
            } else {
                printf("Sent SIGTERM to PID %d\n", pid);
            }
            }
        } else if (state == 0) {
        printf("%d", log_state);
        if (kill(pid, SIGTERM) == -1) {
            printf("Error : Failed to send SIGTERM %d\n", pid);
        } else {
            printf("Sent SIGTERM to PID %d\n", pid);
        }
        } else {
            printf("Somethinge went wrong");
        }
    }
    
    remove("setup.log");
    fclose(log);
    exit (0);

}

int main (int argc, char *argv[]){
    int state = 0;
     
 
    if (strcmp(argv[1], "-o") == 0 && argc > 3){
        for (int i = 2; i < argc; i += 2){
            open(argv[i], atoi(argv[i + 1]), state);
        }
    }
    else if (strcmp(argv[1], "-k") == 0){
        if (argc == 3){
            state = 1;
            stop(state);
        } else if (argc == 2) {
            stop(state);
        } else {
            printf("Error : Invalid amount of arguments");
        }
    }
    else if (strcmp(argv[1], "-f") == 0 && argc == 3){
        state = 1;
        file_open(argv[2], state);
    }
    else {
        printf("Error : Wrong arguments\n try >> -o For manual setup \n \t-f For config file setup \n \t-k For closing setup");
        return 1;
    }

    return 0;
}