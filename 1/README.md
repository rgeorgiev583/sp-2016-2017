# Въведение


## Теми, разглеждани в курса

Вдясно са посочени системните извиквания, представени в съответната тема:

* Входно-изходни операции без буфериране: `open(2)`, `creat(2)`, `read(2)`, `write(2)`, `close(2)`
* Отиване на позиция в отворен файл: `lseek(2)`
* Копиране на файлови дескриптори и пренасочване на стандартния вход и изход: `dup(2)`, `dup2(2)`
* Стартиране на изпълним файл чрез набора от системни извиквания `exec`: `execl(2)`, `execlp(2)`, `execv(2)`, `execvp(2)`
* Конкурентност на ниво процес: `fork(2)`, `wait(2)`, `waitpid(2)`, `exit(2)`
* Писане на прост команден интерпретатор (*shell*)
* Междупроцесна комуникация чрез канали (*pipes*): `pipe(2)`
* Междупроцесна комуникация чрез сигнали: `kill(2)`, `signal(2)`
* Междупроцесна комуникация чрез споделена памет: `mmap(2)`, `munmap(2)`
