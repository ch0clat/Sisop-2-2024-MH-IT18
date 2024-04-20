// admin.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 256

pid_t processes[MAX_PROCESSES];
int num_processes = 0;
int monitor_mode = 0;
int kill_mode = 0;
char *username;
FILE *log_file;

void log_process(pid_t pid, char *process_name, int status) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%d:%m:%Y-%H:%M:%S", t);
    fprintf(log_file, "[%s]-%d-%s-%s\n", timestamp, pid, process_name, status ? "JALAN" : "GAGAL");
    fflush(log_file);
}

void handle_child_signal(int sig) {
    pid_t pid;
    int status;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i] == pid) {
                char process_name[MAX_COMMAND_LENGTH];
                sprintf(process_name, "/proc/%d/cmdline", pid);
                FILE *f = fopen(process_name, "r");
                if (f) {
                    fgets(process_name, MAX_COMMAND_LENGTH, f);
                    fclose(f);
                    log_process(pid, process_name, WEXITSTATUS(status) == 0);
                }
                processes[i] = -1;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <command> <username>\n", argv[0]);
        return 1;
    }

    username = argv[2];
    char log_filename[256];
    sprintf(log_filename, "%s.log", username);
    log_file = fopen(log_filename, "a");
    if (!log_file) {
        perror("fopen");
        return 1;
    }

    signal(SIGCHLD, handle_child_signal);

    if (strcmp(argv[1], "-m") == 0) {
        monitor_mode = 1;
        while (1) {
            pid_t pid = fork();
            if (pid == 0) {
                char *args[] = {"ps", "-u", username, "-o", "pid,cmd", NULL};
                execvp("ps", args);
                return 0;
            } else if (pid > 0) {
                processes[num_processes++] = pid;
            }
            sleep(1);
        }
    } else if (strcmp(argv[1], "-s") == 0) {
        monitor_mode = 0;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i] > 0) {
                kill(processes[i], SIGTERM);
            }
        }
    } else if (strcmp(argv[1], "-c") == 0) {
        kill_mode = 1;
        while (1) {
            pid_t pid = fork();
            if (pid == 0) {
                char *args[] = {"pkill", "-u", username, NULL};
                execvp("pkill", args);
                return 0;
            } else if (pid > 0) {
                waitpid(pid, NULL, 0);
            }
            sleep(1);
        }
    } else if (strcmp(argv[1], "-a") == 0) {
        kill_mode = 0;
    }

    fclose(log_file);
    return 0;
}