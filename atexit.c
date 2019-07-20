#include <stdlib.h>
#include <stdio.h>

static void my_exit1(void);
static void my_exit2(void);

int main() {
    if (atexit(my_exit1) != 0) {
        printf("can't register exit function\n");
        exit(-1);
    }

    if (atexit(my_exit2) != 0) {
        printf("can't register exit function\n");
        exit(-1);
    }

    printf("main is done\n");
}

static void my_exit1(void) {
    printf("my exit 1 is called\n");
}

static void my_exit2(void) {
    printf("my exit 2 is called\n");
}
