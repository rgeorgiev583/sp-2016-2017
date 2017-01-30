#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
    argv[0] = "wc";

    if (!strcmp(argv[1], "chars"))
        argv[1] = "-c";
    else if (!strcmp(argv[1], "words"))
        argv[1] = "-w";
    else if (!strcmp(argv[1], "lines"))
        argv[1] = "-l";

    printf("%s", argv[0]);
    printf("%s", argv[1]);
    execvp(argv[0], argv);
}
