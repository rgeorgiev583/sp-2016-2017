#include <string.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    argv[0] = "wc";

    if (!strcmp(argv[1], "chars"))
        argv[1] = "-c";
    else if (!strcmp(argv[1], "words"))
        argv[1] = "-w";
    else if (!strcmp(argv[1], "lines"))
        argv[1] = "-l";

    execvp(argv[0], argv);
}
