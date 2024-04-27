#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

void daemonStart() {
    pid_t pid, sid;
    
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);
            
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
    
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
    
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

void HSignal(int sig) {
    
}

int main() {
    signal(SIGRTMIN, HSignal);
    signal(SIGUSR1, HSignal);
    signal(SIGUSR2, HSignal);
    daemonStart();
}
