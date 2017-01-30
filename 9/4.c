#include <signal.h>
#include <stdio.h>

void handler(int sig)
{
    if (sig == SIGINT)
        printf("Try harder next time!\n");
}

int main()
{
    signal(SIGINT, handler);
    while (1);
    return 0;
}
