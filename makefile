all: main.o ll_functions.o song_functions.o populate.o
	gcc -o song_functions.out main.o ll_functions.o song_functions.o populate.o

ll_functions.o: ll_functions.c headers/ll_functions.h
	gcc -c ll_functions.c

song_functions.o: song_functions.c headers/song_functions.h
	gcc -c song_functions.c

populate.o: populate.c headers/song_functions.h headers/ll_functions.h
	gcc -c populate.c

main.o: main.c headers/song_functions.h headers/ll_functions.h
	gcc -c main.c 

clean:
	-rm -r *.o
	-rm -r *~

run: all
	./song_functions.out
