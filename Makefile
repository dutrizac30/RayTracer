out.ppm: main
	./main > out.ppm

main: test_all main.c vec3.h vec3.c ray.h ray.c
	gcc -Wall -Wextra -ansi -pedantic main.c vec3.c ray.c -o main 

viewmac: out.ppm
	open out.ppm

test_all: test/vec3_test test/ray_test 

test/vec3_test: test/vec3_test.c
	gcc -Wall -Wextra -ansi -pedantic vec3.c test/vec3_test.c -o test/vec3_test
	./test/vec3_test

test/ray_test: test/ray_test.c
	gcc -Wall -Wextra -ansi -pedantic vec3.c ray.c test/ray_test.c -o test/ray_test
	./test/ray_test

sandbox: sandbox.c
	gcc -Wall -Wextra -ansi -pedantic sandbox.c -o sandbox
	./sandbox

clean:
	rm -f main out.ppm test/vec3_test test/ray_test sandbox


