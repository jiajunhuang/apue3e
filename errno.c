#include <sys/errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
}
