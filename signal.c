#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void sig_int(int);

#define MAXLINE 1024

int main() {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        printf("failed to install signal handler for SIGINT\n");
        exit(-1);
    }

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0) {
            printf("fork error\n");
            exit(-1);
        } else if (pid == 0) {
            // child
            execlp(buf, buf, (char *)NULL);
            // should not execute here in the right case
            printf("couldn't execute: %s", buf);
            exit(-1);
        } else {
            // parent
            if ((pid = waitpid(pid, &status, 0)) < 0) {
                printf("waitpid error\n");
                exit(-1);
            }
        }
        printf("%% ");
    }
}

void sig_int(int signo) {
    printf("interrupt\n%% ");
}
