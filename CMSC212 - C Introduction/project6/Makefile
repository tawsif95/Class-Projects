#%=wildcard
#$^=all dependencies
#$@=target
#$<=first dependence only
#www.gnu.org/software/make/manual

CC= gcc
CFLAGS= -ansi -pedantic-errors -Werror -Wall -g -fPIC
LIBFLAGS= -nostdlib -shared -fPIC -W1,-soname,$@

all : public01.x public02.x public03.x public04.x public05.x public06.x \
public07.x public08.x public09.x public10.x public11.x public12.x \
testerlist.x testerarray.x main-list.x main-array.x

libarray.so : array.o
	$(CC) $(LIBFLAGS) $^ -o $@

liblist.so : list.o
	$(CC) $(LIBFLAGS) $^ -o $@

testerlist.x : tester.o liblist.so        
	$(CC) $(CFLAGS) $< -L. -llist -o testerlist.x

testerarray.x : tester.o libarray.so
	$(CC) $(CFLAGS) $< -L. -llist -o testerarray.x	
	
tester.o : tester.c table.h
	$(CC) $(CFLAGS) -c tester.c
	
list.o : list.c list.h table.h
	$(CC) $(CFLAGS) -c list.c

array.o : array.c array.h table.h
	$(CC) $(CFLAGS) -c array.c
	
main-list.x: main.o liblist.so
	$(CC) $(CFLAGS) $< -L. -llist -o main-list.x
	
main-array.x : main.o libarray.so
	$(CC) $(CFLAGS) $^ -L. -larray -o main-array.x
	
main.o: main.c table.h
	$(CC) $(CFLAGS) -c main.c

#1
public01.x : public01.o liblist.so
	$(CC) $(CFLAGS) $< -L. -llist -o public01.x
	
public01.o : public01.c list.h table.h
	$(CC) $(CFLAGS) -c public01.c

#2	
public02.x : public02.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public02.x
	
public02.o : public02.c array.h table.h
	$(CC) $(CFLAGS) -c public02.c

#3
public03.x : public03.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public03.x
	
public03.o : public03.c array.h table.h
	$(CC) $(CFLAGS) -c public03.c
	
#4
public04.x : public04.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public04.x
	
public04.o : public04.c array.h table.h
	$(CC) $(CFLAGS) -c public04.c

#5	
public05.x : public05.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public05.x
	
public05.o : public05.c array.h table.h
	$(CC) $(CFLAGS) -c public05.c
	
#6
public06.x : public06.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public06.x
	
public06.o : public06.c array.h table.h
	$(CC) $(CFLAGS) -c public06.c
	
#7
public07.x : public07.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public07.x
	
public07.o : public07.c array.h table.h
	$(CC) $(CFLAGS) -c public07.c

#8
public08.x : public08.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public08.x
	
public08.o : public08.c array.h table.h
	$(CC) $(CFLAGS) -c public08.c
	
#9
public09.x : public09.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public09.x
	
public09.o : public09.c array.h table.h
	$(CC) $(CFLAGS) -c public09.c
	
#10
public10.x : public10.o liblist.so
	$(CC) $(CFLAGS) $< -L. -llist -o public10.x
	
public10.o : public10.c list.h table.h
	$(CC) $(CFLAGS) -c public10.c
	
#11
public11.x : public11.o libarray.so
	$(CC) $(CFLAGS) -lm $< -L. -larray -o public11.x
	
public11.o : public11.c array.h table.h
	$(CC) $(CFLAGS) -c public11.c
	
#12
public12.x : public12.o libarray.so
	$(CC) $(CFLAGS) $< -L. -larray -o public12.x
	
public12.o : public12.c array.h table.h
	$(CC) $(CFLAGS) -c public12.c


clean: 
	rm -f public*.x
	rm -f tester.x
	rm -f *.so

memtest%: public%.x
	valgrind -q --leak-check=yes ./public$*.x

