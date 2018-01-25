all:
	g++ main.cpp -std=c++14 -Werror -Wall -pedantic-errors
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./a.out; exec /bin/bash -i'" 