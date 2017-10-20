#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>



//Functions for the linked list


//Adds a node to the front of the list with the given value
//Returns a pointer to the beginning of the list
struct song_node * insert_front(struct song_node * new_song){
    //Find first char of song_name, map a to 0
    char letter = new_song->artist[0];
    int map_letter = letter - 97;

    //Inserts node
    struct song_node * temp = alph_table[map_letter];
    alph_table[map_letter] = new_song;
    new_song->next = temp;
    return alph_table[map_letter];
}
struct song_node * insert_between(struct song_node * prev, struct song_node * curr, struct song_node * next){
  prev -> next = curr;
  curr -> next = next;
  return curr;
}
//Insert node in correct area
struct song_node * insert_order(struct song_node * new_song){

    //Find first char of song_name, map a to 0
    char letter = new_song->artist[0];
    int map_letter = letter - 97;

    //Pointer to first song_node in list
    struct song_node * current = alph_table[map_letter];

    //If first node in list, insert_front()
    if (!current){
      return insert_front(new_song);
    }

    char * song_name = new_song->name;
    char * song_artist = new_song->artist;
    
    //If there is only one node in the list
    if (!current->next){
      printf("bubble, %s\n", new_song->name);
      //If the artist is equal and the new song is ahead
      if (strcmp(current->artist, song_artist) == 0 && strcmp(current->name,song_name) < 0){
	return insert_between(current, new_song, current->next);
      }
      //else put new song in back
      else{
	current->next = new_song;
	return current->next;
      }
    }

    //Look for correct location, add node
    while(current->next){
      printf("before\n");

      //Is the next author after the new author?
      if(strcmp(current->next->artist,song_artist) > 0){
        printf("artist after\n");
	return insert_between(current,new_song,current->next);
      }
      if(strcmp(current->next->artist,song_artist) == 0){
	//Is the next song after the new song?
	printf("artist ==\n");
	if(strcmp(current->next->name,song_name) > 0){
	  printf("song after \n");
	  return insert_between(current,new_song,current->next);
	}
	if(strcmp(current->next->name,song_name) == 0){
	  printf("song == \n");
	  return current -> next;
	}
      }
   
      //Continue otherwise
      printf("%s: next is %s", current->name, current->next->name);
      //break;
      if (current->next){
	current = current->next;
      }
      else{
	current->next = new_song;
	return current->next;
      }
    }
    

    printf("bruh\n");
    return 0;
}

//Prints out the list, with song name and its artist
void print_list(struct song_node * current){
    while(current){
        //Standard print formatting
        printf("Song Name: %s \n\t\t\t\t\t By:%s\n", current->name, current->artist);
        current = current->next;
    }
}

//Find and return a pointer to a node based on artist and song name
//Otherwise returns 0
struct song_node * find_element_song(char * song_name, char * song_artist){

    //Find first song of artist
    struct song_node * current = first_element_artist(song_artist);

    while(current){
 	//If the artist is not the same, break
	if(strcmp(current->artist,song_artist) != 0){
	    break;
        }
	//Return the correct node
	if(strcmp(current->name,song_name) == 0){
	    return current;
	}
	else{
	    //Continue otherwise
	    current = current->next;
	}
    }
    return 0;
}


//Find and return a pointer to the first song of an artist based on artist name
struct song_node * first_element_artist(char * song_artist){
    //Find first char of song_name, map a to 0
    char letter = song_artist[0];
    int map_letter = letter - 97;

    //Pointer to first song_node in list
    struct song_node * current = alph_table[map_letter];

    while(current){
 	//If the current artist is after the queried search, break
	if(strcmp(current->artist,song_artist) > 0){
	    break;
        }
	//If the current artist is the queried artist, return
	if(strcmp(current->artist,song_artist) == 0){
	    return current;
	}
	else{
	    //Continue otherwise
	    current = current->next;
	}
    }
    return 0;

}

//Return a pointer to random element in the list.
struct song_node * random_element(){
    //For random numbers within a range:
    //rand() % (max_number + 1 - minimum_number) + minimum_number
    //We want min 0, max length of linked list minus 1
    int list_in_table = rand() % (65 + 1 - 0) + 0;

    struct song_node * current = alph_table[list_in_table];

    //If list is empty, try again
    if (!current){
	return random_element();
    }

    //Count number of elements in list
    register int count = 1;
    while (current->next){
	current = current->next;
	count++;
    }

    //Access the random node
    int rand_node = rand() % (count + 1 - 0) + 0;
    current = alph_table[list_in_table];
    while (!rand_node){
	current = current->next;
        rand_node--;
    }

    //Return the random node
    return current;
}


//Free node
void free_node(struct song_node * element){

    //Find first char of song_name, map a to 0
    char letter = element->artist[0];
    int map_letter = letter - 97;

    //Pointer to first song_node in list
    struct song_node * current = alph_table[map_letter];
    struct song_node *previous = current;

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

    struct song_node *list;
    struct song_node *temp;

    register int i = 0;
    for(i = 0; i<26; i++){
	list = alph_table[i];
	if(list){
	  while(list->next){
            temp = list -> next;
            free(list);
            list = temp;
	  }
	  free(list);
	  alph_table[i] = 0;
	}
    }

}
