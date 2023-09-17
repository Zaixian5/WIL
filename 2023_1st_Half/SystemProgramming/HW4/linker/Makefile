main: main.o copy.o
	gcc -o main main.o copy.o
main.o: main.c
	gcc -Wall -g -c main.c
copy.o: copy.c
	gcc -Wall -g -c copy.c
clean:
	rm  -f main *.o

