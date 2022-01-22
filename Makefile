CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -g

all: sorting

sorting:	sorting.o bubble.o quick.o queue.o shell.o set.o stack.o compare.o
	$(CC) -o sorting sorting.o bubble.o quick.o queue.o shell.o set.o stack.o compare.o

sorting.o:	sorting.c
	$(CC) $(CFLAGS) -c sorting.c

bubble.o:	bubble.c
	$(CC) $(CFLAGS) -c bubble.c

quick.o:	quick.c
	$(CC) $(CFLAGS) -c quick.c

queue.o:	queue.c
	$(CC) $(CFLAGS) -c queue.c

shell.o:	shell.c
	$(CC) $(CFLAGS) -c shell.c

set.o:		set.c
	$(CC) $(CFLAGS) -c set.c

compare.o:	compare.c
	$(CC) $(CFLAGS) -c compare.c

stack.o:	stack.c
	$(CC) $(CFLAGS) -c stack.c

format:	
	clang-format -i -style=file sorting.c bubble.c bubble.h set.c set.h compare.c compare.h stack.c stack.h shell.c shell.h queue.c queue.h 

clean:
	rm -f sorting *.o

