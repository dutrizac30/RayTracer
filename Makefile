out.ppm: main
	./main > out.ppm

main: main.c
	gcc -Wall -Wextra -ansi -pedantic main.c -o main

clean: 
	rm main out.ppm



