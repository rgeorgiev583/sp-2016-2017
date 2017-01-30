#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LEN 10

int main(int argc, char** argv)
{
    if (argc < 3)
        exit(1);

    int count_files = atoi(argv[1]), count_num = atoi(argv[2]);

    for (int i = 0; i < count_files; i++)
        if (!fork())
        {
            char i_str[MAX_LEN];
            sprintf(i_str, "%d", i);
            int fd_read = open(i_str, O_RDONLY);
            char i_sum_str[MAX_LEN];
            sprintf(i_sum_str, "%d.sum", i);
            int fd_write = open(i_sum_str, O_CREAT | O_TRUNC | O_WRONLY, 0x644);
            int sum = 0;

            for (int i = 0; i < count_num; i++)
            {
                int num;
                if (read(fd_read, (char*)&num, sizeof(int)))
                    sum += num;
            }

            write(fd_write, (const char*)&sum, sizeof(int));
            close(fd_write);
            close(fd_read);
        }

    int sum = 0;

    for (int i = 0; i < count_files; i++)
    {
        char i_sum_str[MAX_LEN];
        sprintf(i_sum_str, "%d.sum", i);
        int fd = open(i_sum_str, O_RDONLY), num;
        read(fd, (char*)&num, sizeof(int));
        sum += num;
    }

    printf("%d\n", sum);
}
