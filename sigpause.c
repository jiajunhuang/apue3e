#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_alarm(int signo) {
    printf("signal received\n");
}

int main() {
    if (signal(SIGALRM, sig_alarm) == SIG_ERR) {
        printf("failed to install signal handler\n");
        return -1;
    }

    alarm(2);
    pause();

    printf("wake up from pause since received signal\n");
}
