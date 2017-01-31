#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv)
{
    const char *filename = NULL, *option = NULL;

    if (argc < 2)
        return 1;
    else if (argc > 2 && '-' == *argv[1])
    {
        option = argv[1];
        filename = argv[2];
    }
    else
        filename = argv[1];

    close(0);
    open(filename, O_RDONLY);
    execlp("wc", "wc", option, NULL);
}
