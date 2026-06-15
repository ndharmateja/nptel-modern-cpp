$(shell mkdir -p build)

all: build/main

build/main: build/main.o build/fact.o
	gcc build/fact.o build/main.o -o build/main

build/main.o: fact.h
	gcc main.c -c -o build/main.o

build/fact.o: fact.h
	gcc fact.c -c -o build/fact.o

clean:
	rm -rf build

run: build/main
	./build/main