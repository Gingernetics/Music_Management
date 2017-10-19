#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>

//Wrapper functions for user interface


//Add song nodes, and returns their new location
struct song_node * insert_song(char * song_name, char * song_artist){
    //Find first char of song_name, map a to 0
    char letter = song_name[0];
    int map_letter = letter - 97;
    
    //Check if song already exists
    struct song_node *already_in = 0;
    already_in = find_song(song_name, song_artist);
    if(already_in){
        return already_in;
    }

    //Create new node with name and artist information
    struct song_node *new_song = (struct song_node*)malloc(sizeof(struct song_node));
    new_song -> name = song_name;
    new_song -> artist = song_artist;
        

    //Test for empty linked lists
    if(alph_table[map_letter]){
    	return insert_front(new_song);
    }    
        

    else{
        return insert_order(new_song);
    }
}


//Search for and return pointer to song given song and artist name
//Returns 0 if song not found
struct song_node * find_song(char * song_name, char * song_artist){
    return find_element_song(song_name, song_artist);
}

//Search for and return pointer to first song by artist
//Returns 0 if song not found
struct song_node * find_artist(char * song_artist){
    return first_element_artist(song_artist);
}

//Print out all the entries under a certain letter
void print_entries_char(char character){
    // 'a' is 97, 'z' is 122
    int i = (character - 97);
    //Side-effect of printing excess requested by teacher
    print_list(alph_table[i]);
}
    

//Print out all the songs of a certain artist
void print_entries_artist(char * song_artist){
    //Side-effect of printing excess requested by teacher
    print_list(first_element_artist(song_artist));
}

//Shuffle - print out a series of randomly chosen songs
void random_song(int quantity){
    while (quantity-- > 0){
        //Access random node
        struct song_node *new_node = random_element();
        //Standard print formatting
        printf("Song Name: %s \t By:%s\n", new_node->name, new_node->artist);
    }    
}
  

//Delete a song
void delete_song(char * song_name, char * song_artist){
    free_node(find_song(song_name, song_artist));
}

//Delete all the songs
void clear_program(){
    free_list();
}
