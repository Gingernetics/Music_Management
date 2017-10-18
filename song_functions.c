#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>

//Wrapper functions for user interface

//REWRITE
//Add song nodes, and returns their new location
struct song_node * insert_song(char * song_name, char * song_artist){

    //Test to find artist
    if(find_artist(song_artist)){
    
        //Create new node with name and artist information
        struct song_node *new_song = (struct song_node*)malloc(1, sizeof(struct song_node));
        new_song -> name = song_name;
        new_song -> artist = song_artist;
        
        //Check if song already exists
        struct song_node *already_in = 0;
        already_in = find_song(song_name, song_artist);
        if(already_in){
            return already_in;
        }
        else{
            //Artist guaranteed to be listed
            return insert_song(struct song_node * new_song);
        }
    }
    else{
        //Add artist and recurse the function
        add_artist(song_artist);
        return insert_song(song_name, song_artist);
    }
}

//DELETE
//Helper function for insert_song
void add_artist(char * song_artist){
    
    //Reference beginning of list
    struct song_node *current = HEAD;
    struct song_node *new_artist;
    new_artist -> name = 0;
    new_artist -> artist = song_artist;
    new_artist -> next = 0;

    while(current->next){
	    if(strcmp(current->next->artist,song_artist) < 0){
			insert_between(current, new_artist , current->next);
		}
		current = current->next;
    }
    insert_front(new_artist);
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
    char* char_query = character;
    //Side-effect of printing excess requested by teacher
    print_list(find_element_song("*", character));
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
void delete_song(char * song_name){
    free_node(find_song(song_name, "*"));
}

//Delete all the songs
void clear_program(){
    free_list();
}
