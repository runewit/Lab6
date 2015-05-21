all: main.c tree.c
	gcc -o main.c tree.c -I .

run:
	./main.c

clean:
	rm -f main
	rm -f t
	
test: 
	gcc -o t     -I .
	./t
	rm -f t