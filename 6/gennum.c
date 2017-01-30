#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 10

int main(int argc, char** argv)
{
    if (argc < 3)
        exit(1);

    int count_files = atoi(argv[1]), count_num = atoi(argv[2]), offset = 1;
    char count_num_str[MAX_LEN];
    sprintf(count_num_str, "%d", count_num);

    for (int i = 0; i < count_files; i++)
    {
        char i_str[MAX_LEN], offset_str[MAX_LEN];
        sprintf(i_str, "%d", i);
        sprintf(offset_str, "%d", offset);

        if (!fork())
            execl("./helper", i_str, offset_str, count_num_str, NULL);

        offset += count_num;
    }

    return 0;
}
