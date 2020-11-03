all: main.o list.o
	gcc -o list main.o list.o

list.o: list.c list.h
	gcc -c list.c 

main.o: main.c list.h
	gcc -c main.c

clean:
	rm *.o

run: list
	./list 