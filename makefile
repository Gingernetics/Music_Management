all: main.o ll_functions.o song_functions.o populate.o
	gcc -o song_functions.out main.o ll_functions.o song_functions.o populate.o

ll_functions.o: ll_functions.c ll_functions.h
	gcc -c ll_functions.c

song_functions.o: song_functions.c song_functions.h
	gcc -c song_functions.c

populate.o: populate.c song_functions.h ll_functions.h
	gcc -c populate.c

main.o: main.c song_functions.h ll_functions.h
	gcc -c main.c 

clean:
	-rm *.o
	-rm ~

run: all
	./song_functions.out
