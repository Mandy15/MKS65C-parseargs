all: parseargs.o
	gcc -o parseargs parseargs.o

demo.o: parseargs.c
	gcc -c parseargs.c

clean:
	rm parseargs parseargs.o

run:
	./parseargs $(args)
