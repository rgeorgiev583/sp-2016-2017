#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	if (argc < 4)
		printf("Not enought arguments");
	else
	{
		int n = atoi(argv[1]);
		int fd1, fd2;
		fd2 = open(argv[3], O_RDONLY);
		fd1 = open(argv[2], O_RDWR);
		lseek(fd1, n, SEEK_END);

		char buf[512];
		while(n = read(fd2, buf, 512))
            write(fd1, buf, n);

        close(fd1);
        close(fd2);
	}

    return 0;
}
