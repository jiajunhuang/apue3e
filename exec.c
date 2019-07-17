#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 1024

int main() {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0; // replace newline with NULL
        }

        if ((pid = fork()) < 0) {
            printf("fork error\n");
            exit(-1);
        } else if (pid == 0) {
            // child
            execlp(buf, buf, (char *)0);
            // if exec succeed, this will not be executed
            printf("couldn't execute %s\n", buf);
            exit(-1);
        } else {
            // parent
            pid = waitpid(pid, &status, 0);
            if (pid < 0) {
                printf("waitpid error\n");
                exit(-1);
            }
            printf("%% ");
        }
    }
}
