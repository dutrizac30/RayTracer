out.ppm: main
	./main > out.ppm

main: main.c
	gcc -Wall -Wextra -ansi -pedantic main.c -o main

viewmac: out.ppm
	open out.ppm

test_all:
	gcc -Wall -Wextra -ansi -pedantic vec3.c test/vec3_test.c -o test/vec3_test
	./test/vec3_test

sandbox: sandbox.c
	gcc -Wall -Wextra -ansi -pedantic sandbox.c -o sandbox
	./sandbox

clean:
	rm -f main out.ppm test/vec3_test sandbox



