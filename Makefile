out.ppm: main
	./main > out.ppm

main: main.c
	gcc -Wall -Wextra -ansi -pedantic main.c -o main

viewmac: out.ppm
	open out.ppm

clean: 
	rm main out.ppm



