all:
	gcc -c -g *.c src/*.c -std=c99 -Werror -Wall -pedantic-errors -I/usr/include/libxml2/ -I./include -I./../include 
	gcc *.o -o a.out -lprogbase -lxml2 -ljansson 
	rm *.o 
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./a.out; exec /bin/bash -i'" 