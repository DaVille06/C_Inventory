build:
	gcc -Wall -std=c99 ./src/*.c -o structitem

run:
	./structitem

clean:
	rm structitem