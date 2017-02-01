#include <stdlib.h>
#include<sys/types.h>
#include<signal.h>

int main(int argc, char **argv)
{
    int i;
    for(i=1; i<argc; i++){
        kill(atoi(argv[i]), SIGKILL);
    }

    return 0;
}

