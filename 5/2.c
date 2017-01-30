#include <unistd.h>


int main(int argc, char** argv)
{
    argv[0] = "wc";
    execvp(argv[0], argv);
}
