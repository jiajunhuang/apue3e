#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void gen_child() {
    int pid;

    if ((pid = fork()) == 0) { // child
        printf("child exit\n");
        exit(0);
    }
}

int main() {
    printf("before fork\n");

    for (int i = 0; i < 10; i++) {
        gen_child();
    }

    // wait for the first child
    if (waitpid(-1, NULL, 0)) {
        printf("waitpid success\n");
    }
}
