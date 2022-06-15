out.ppm: main
	./main > out.ppm

main: test main.c
	gcc -Wall -Wextra -ansi -pedantic main.c -o main

viewmac: out.ppm
	open out.ppm

test:
	gcc -Wall -Wextra -ansi -pedantic vec3.c tests/vec3_test.c -o tests/vec3_test
	./tests/vec3_test

clean:
	rm main out.ppm tests/vec3_test



