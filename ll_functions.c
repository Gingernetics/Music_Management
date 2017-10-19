#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>

//Functions for the linked list

//Helper function to find the correct linked list associated with the 
//author's firt letter
struct song_node * find_letter(struct song_node * new_song){
    //Find first char of song_name, map a to 0
    char letter = new_song->name[0];
    int map_letter = letter - 97;

    //Pointer to first song_node in list
    return alph_table[map_letter];


}



//Adds a node to the front of the list with the given value
//Returns a pointer to the beginning of the list
struct song_node * insert_front(struct song_node * new_song){
    //Find first char of song_name, map a to 0
    char letter = new_song->name[0];
    int map_letter = letter - 97;

    //Inserts node
    alph_table[map_letter] = new_song;
    new_song->next = temp;

    return alphtable[map_letter];
}

//Insert node in correct area
struct song_node * insert_song(struct song_node * new_song){

    //First 
    struct song_node * current = find_letter(new_song);

    char * song_name = new_song->name;
    char * song_author = new_song->author;

    while(current){
		if(strcmp(current->artist,song_artist) < 0){ 
			
		}
		current = current->next;
    }    
}

//Prints out the list, with song name and its artist
void print_list(struct song_node * current){

    while(current->next){
        //Standard print formatting
        printf("Song Name: %s \t By:%s\n", current->name, current->artist);
        current = current->next;
    }
}

//Find and return a pointer to a node based on artist and song name
struct song_node * find_element_song(char * song_name, char * song_artist){
    //if artist is "*", search by song name for a particular node, return it
    //NOT DONE
    //if name is "*", compare author name to char for a particular node, return start of list

}

//REWRITE 
//Find and return a pointer to the first song of an artist based on artist name
struct song_node * first_element_artist(char * song_artist){

    //Reference beginning of list
    struct song_node *current = HEAD->next;
    //NOT DONE --  see case where artist has no song
    while(current){
		if(strcmp(current->artist,song_artist) == 0){ 
			break;
		}
		current = current->next;
    }
    return current;
}

//Return a pointer to random element in the list.
struct song_node * random_element(){
    //For random numbers within a range:
    //rand() % (max_number + 1 - minimum_number) + minimum_number
    //We want min 0, max length of linked list minus 1
    int i = rand() % (65 + 1 - 0) + 0;
	i += 'a';
    //NOT DONE   
    
}

//REWRITE 
//Free node
void free_node(struct song_node * element){

    //Reference beginning of list
    struct song_node *current = HEAD->next;
    struct song_node *previous = HEAD;
    
    char * test_name = element->name;
    
    while(current->next){
        //Look for the correct node
		if(strcmp(current->name, test_name) == 0){ 
		    //When found, release and reconnect linked list
			struct song_node *tmp_next = current->next;
			free(current);
			previous->next = tmp_next;			
			break;
		}
		previous = current;
		current = current->next;
	}
}
 

//Frees all the nodes in the list
//Returns a pointer to the beginning of the list
void free_list(){
    struct song_node *list = HEAD->next;
    struct song_node *temp;
    while(list->next){
        temp = list -> next;
        free(list);
        list = temp;
    }
    free(list);
    return HEAD->next;
}
