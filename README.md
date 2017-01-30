# sp-2016-2017

Тук можете да намерите материалите и задачите, давани по време на курса по системно програмиране на специалност Компютърни науки във ФМИ през учебната 2016/2017 година.


## Как да си компилираме примерните задачи

За да компилирате всички задачи (т.е. C-файлове) в текущата папка, използвайте тази команда:

		$ make

За да компилирате една конкретна задача, ползвайте следното:

		$ make име

където `име.c` е името на файла с изходния код на C (на `make` го подаваме без `.c` частта).
Командният ред на компилатора, който е посочен в *Makefile*-а, е следният (можете да го използвате, ако нямате програмата `make` на системата):

		$ cc -pedantic -Wall -O3 име.c -o име

За да изтриете генерираните изпълними файлове, можете да използвате следната команда:

		$ make clean


## Препоръчана литература

* *[Advanced Programming in the Unix environment](https://en.wikipedia.org/wiki/Advanced_Programming_in_the_Unix_Environment)*, third edition, W. Richard Stevens and Stephen A. Rago, Addison-Wesley, 2013, [ISBN 978-0-321-63773-4](https://en.wikipedia.org/wiki/Special:BookSources/9780321637734) (библията на системното програмиране за Unix; може да я свалите директно [оттук](https://github.com/shihyu/Linux_Programming/raw/master/books/Advanced.Programming.in.the.UNIX.Environment.3rd.Edition.0321637739.pdf))
* *[The Unix Programming Environment](https://en.wikipedia.org/wiki/The_Unix_Programming_Environment)*, Brian W. Kernighan and Rob Pike, Prentice Hall, 1984, [ISBN 0-13-937681-X](https://en.wikipedia.org/wiki/Special:BookSources/0-13-937681-X) (класическа книга за Unix програмиране; може да я свалите директно [оттук](https://bin.sc/Teaching/2014/JavaScript/Resources/The%20Unix%20Programming%20Environment.pdf))
