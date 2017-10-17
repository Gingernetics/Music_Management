#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"



//assumes that artist exists
struct song_node * insert_song(struct song_node * current, char * song_name, char * song_artist){
	//Creates new song_node with artist and song name
	struct song_node *new = (struct song_node*)calloc(1, sizeof(struct song_node));
	new -> name = song_name;
	new -> artist = song_artist;

	//Finds the corresponding artist
	while(current){
		if(strcmp(current->artist,song_artist) == 0){ 
			break;
		}
		current = current->next;
	}
	//We've reached the artist, insert song to correct location
	//char * last_song;		
	while(current->next){
		if(strcmp(current->next->name,song_name) < 0){
			insert_between(current, new, current->next);
		}
		current = current->next;
	}
}


