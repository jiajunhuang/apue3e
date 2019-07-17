#include <unistd.h>
#include <stdio.h>

int main() {
    printf("uid: %d, gid: %d\n", getuid(), getgid());
}
