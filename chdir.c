#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (chdir("/tmp") < 0) {
        printf("failed to chdir\b");
        exit(-1);
    }

    printf("chdir to /tmp succeed!\n");
}
