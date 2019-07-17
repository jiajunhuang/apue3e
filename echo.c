#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 4096

int main() {
    int n = 0;
    char buf[BUFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            printf("write error\n");
            exit(-1);
        }
    }

    if (n < 0) {
        printf("read error\n");
        exit(01);
    }
}
