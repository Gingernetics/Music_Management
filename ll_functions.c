#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include "headers/test_functions.h"
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

  //printf("%s, %s\n", current->next->artist, current->next->name);

  char * song_name = new_song->name;
  char * song_artist = new_song->artist;
  //If first node in list, insert_front()
  if (!current){
    return insert_front(new_song);
  }
  int cmp_artist = strcmp(current->artist, song_artist);
  int cmp_name = strcmp(current->name, song_name);
  if(cmp_artist > 0 || (cmp_artist == 0 && cmp_name > 0)){
    return insert_front(new_song);
  }
  if(cmp_artist == 0 && cmp_name == 0){
    return current;
  }
  if(!current->next){
    current->next = new_song;
    return current -> next;
  }
    
  //Look for correct location, add node
  while(current->next){
    //Is the next author after the new author?
    if(strcmp(current->next->artist,song_artist) > 0){
      return insert_between(current,new_song,current->next);
    }
    if(strcmp(current->next->artist,song_artist) == 0){
      //Is the next song after the new song?
      if(strcmp(current->next->name,song_name) > 0){
	return insert_between(current,new_song,current->next);
      }
      if(strcmp(current->next->name,song_name) == 0){
	return current -> next;
      }
    }
    //Continue otherwise
    if(current -> next){
      current = current->next;
    }
  }
  //if the song is at the end of the list:
  current->next = new_song;
  return current->next;
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
  int list_in_table = rand() % (25 + 1 - 0) + 0;
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
  if(count == 1){
    return current;
  }

  int rand_node = rand() % count;
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
  if(current == element){
    alph_table[map_letter] = element->next;
    free(current);
  }
  else{
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
