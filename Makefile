all: main.c tree.c
	gcc -o main main.c tree.c -I .

run:
	./main.c

clean:
	rm -f main
	rm -f t