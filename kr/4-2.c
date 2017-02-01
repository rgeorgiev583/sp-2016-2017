#include <unistd.h>


int main(int argc, char** argv)
{
    if (argc < 5)
        return 1;

    int cmdc = (argc - 1) / 2 - 1;
    int fdsr[2], fdsw[2];

    pipe(fdsw);

    if (!fork())
    {
        close(fdsw[0]);

        close(1);
        dup(fdsw[1]);

        execlp(argv[1], argv[1], argv[2], NULL);
    }

    for (int i = 1; i < cmdc; i++)
    {
        fdsr[0] = fdsw[0];
        fdsr[1] = fdsw[1];
        pipe(fdsw);

        close(fdsr[1]);

        if (!fork())
        {
            close(fdsw[0]);

            close(0);
            dup(fdsr[0]);
            close(1);
            dup(fdsw[1]);

            execlp(argv[2 * i + 1], argv[2 * i + 1], argv[2 * i + 2], NULL);
        }

        close(fdsr[0]);
    }

    fdsr[0] = fdsw[0];
    fdsr[1] = fdsw[1];

    close(fdsr[1]);

    close(0);
    dup(fdsr[0]);

    execlp(argv[2 * cmdc + 1], argv[2 * cmdc + 1], argv[2 * cmdc + 2], NULL);
}
