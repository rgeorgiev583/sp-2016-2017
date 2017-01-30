#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main()
{
    //int fd = shm_open("/foobar", O_CREAT | O_RDWR | O_TRUNC, 0x644);
    void* mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (!fork())
    {
        char* baz = mem;
        strcpy(baz, "Hello world!\n");
        write(1, baz, strlen(baz));
    }
    else
    {
        int status;
        wait(&status);
        char* quux = mem;
        write(1, quux, strlen(quux));
    }
}
