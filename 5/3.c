#include <unistd.h>


int main(int argc, char** argv)
{
    execvp(argv[1], argv + 1);
}
