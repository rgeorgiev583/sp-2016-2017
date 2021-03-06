#include <unistd.h>


int main(int argc, char** argv)
{
    // начало на пренасочването на стандартния изход на `grep argv[1..]`
    int fds1[2];
    pipe(fds1);

    // конкуретнтно изпълнение
    if (!fork())
    {
        // затваряме четящия край на канала за писане, тъй като няма да ни е нужен в този случай
        close(fds1[0]);

        // пренасочваме стандартния изход към пишещия файлов дескриптор на канала за писане
        close(1);
        dup(fds1[1]);

        argv[0] = "grep";
        execvp(argv[0], argv);
    }
    // край на пренасочването на `grep argv[1..]`

    // начало на пренасочването на `sort`
    // затваряме пишещия край на канала за четене, тъй като няма да ни е нужен в този случай
    close(fds1[1]);

    int fds2[2];
    pipe(fds2);

    if (!fork())
    {
        // затваряме четящия край на канала за писане, тъй като няма да ни е нужен в този случай
        close(fds2[0]);

        // пренасочваме стандартния вход от четящия файлов дескриптор на канала за четене
        close(0);
        dup(fds1[0]);
        // пренасочваме стандартния изход към пишещия файлов дескриптор на канала за писане
        close(1);
        dup(fds2[1]);

        execlp("sort", "sort", NULL);
    }

    // затваряме четящия край на канала за четене, тъй като няма да ни е нужен повече
    close(fds1[0]);
    // край на пренасочването на `sort`

    // начало на пренасочването на `uniq`
    close(fds2[1]);

    int fds3[2];
    pipe(fds3);

    if (!fork())
    {
        close(fds3[0]);

        close(0);
        dup(fds2[0]);
        close(1);
        dup(fds3[1]);

        execlp("uniq", "uniq", NULL);
    }

    close(fds2[0]);
    // край на пренасочването на `uniq`

    // начало на пренасочването на стандартния вход на `wc -l`
    // затваряме пишещия край на канала за четене, тъй като няма да ни е нужен в този случай
    close(fds3[1]);

    // пренасочваме стандартния вход от четящия файлов дескриптор на канала за четене
    close(0);
    dup(fds3[0]);

    execlp("wc", "wc", "-l", NULL);
}
