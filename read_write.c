#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main() {
    int n;
    char buf[BUFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            printf("write error\n");
            exit(-1);
        }
    }

    if (n < 0) {
        printf("read error\n");
        exit(-1);
    }
}
