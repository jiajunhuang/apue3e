#include <unistd.h>
#include <stdio.h>

int main() {
    printf("before fork\n");

    if (fork() == 0) {
        printf("I'm child, pid %d, ppid %d\n", getpid(), getppid());
    } else {
        printf("I'm parent, pid %d, ppid %d\n", getpid(), getppid());
    }
}
