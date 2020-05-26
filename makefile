.PHONY: clean
all: ./bin/main ./bin/test
test: ./bin/test

./bin/test: ./build/test/main.o ./build/src/func.o ./build/test/test_func.o
	gcc -Wall -Werror -o ./bin/test ./build/test/main.o ./build/src/func.o ./build/test/test_func.o

./bin/main: ./build/src/main.o ./build/src/func.o
	gcc -Wall -Werror -o ./bin/main ./build/src/main.o ./build/src/func.o 


./build/test/main.o: ./test/main.c
	gcc -c -o ./build/test/main.o ./test/main.c

./build/test/test_func.o: ./test/test_func.c
	gcc -c -o ./build/test/test_func.o ./test/test_func.c


./build/src/main.o: ./src/main.c
	gcc -c -o ./build/src/main.o ./src/main.c 

./build/src/func.o: ./src/func.c
	gcc -c -o ./build/src/func.o ./src/func.c 



clean:
	rm -rf ./bin/* ./build/src/*o ./build/test/*o