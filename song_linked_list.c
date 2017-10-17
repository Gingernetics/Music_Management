#include <stdio.h>
#include <stdlib.h>

#include "sll_header.h"

//print_list(struct song_node *current)
//prints out the list, with song name and its artist
void print_list(struct song_node * current){
  while(current->next){
    printf("Song Name: %s \t by:%s\n", current->name, current->artist);
    current = current->next;
  }
}

//insert_front(struct song_node *front, char * song_name, char * song_artist)
//adds a node to the front of the list with the given value
//returns a pointer to the beginning of the list
struct song_node * insert_front(struct song_node * front, char * song_name, char * song_artist){
  struct song_node *new = (struct song_node*)calloc(1, sizeof(struct song_node));
  new -> name = song_name;
  new -> artist = song_artist;
  new -> next = front;
  return new;
}


//free_list(struct node *list)
//frees all the nodes in the list
//returns a pointer to the beginning of the list
struct song_node * free_list(struct song_node * list){
  struct song_node *start = list;
  struct song_node *temp;
  while(list->next){
    temp = list -> next;
    free(list);
    list = temp;
  }
  start = NULL;
  return start;
}
