sumfact: sumfact.o launch
	gcc -o sumfact sumfact.o
sumfact.o: sumfact.c
	gcc -Wall -g -pthread -c sumfact.c
launch: launch.o
	gcc -o launch launch.o
launch.o: launch.c
	gcc -Wall -g -c launch.c
clean:
	rm -rf *.o
