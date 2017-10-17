all: main.o song_linked_list.o
	gcc -o song_functions.exe main.o song_linked_list.o

song_linked_list.o: song_linked_list.c sll_header.h
	gcc -c song_linked_list.c

main.o: main.c sll_header.h
	gcc -c main.c sll_header.h

clean:
	-rm *.o
	-rm *.*~

run: all
	./song_functions.exe
