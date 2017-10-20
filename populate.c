#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include "headers/test_functions.h"


void populate(){
  //Adding many, many songs
  insert_song("make a man out of you", "donny osmond");
  insert_song("chandelier", "sia");
  insert_song("how far ill go", "lin manuel miranda");
  insert_song("legends never die", "against the current");
  insert_song("look what you made me do", "taylor swift");
}

void test_all_functions(){

}
void test_ll_functions(){
  test_insert_front();
  test_insert_order();

}

void test_insert_front(){
  printf("====================================================================\n");
  printf("TESTING INSERT FRONT...\n");

  struct song_node * node1 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node1 -> name = "make a man out of you"; node1 -> artist = "donny osmond";

  struct song_node * node2 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node2 -> name = "chandelier"; node2 -> artist = "sia";

  struct song_node * node3 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node3 -> name = "how far ill go"; node3 -> artist = "lin manuel miranda";

  struct song_node * node4 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node4 -> name = "legends never die"; node4 -> artist = "against the current";

  struct song_node * node5 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node5 -> name = "look what you made me do"; node5 -> artist = "taylor swift";

  struct song_node * node6 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node6 -> name = "you belong with me"; node6 -> artist = "taylor swift";

  struct song_node * node7 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node7 -> name = "test1"; node7 -> artist = "t";

  insert_front(node1);
  insert_front(node2);
  insert_front(node3);
  insert_front(node4);
  insert_front(node5);
  insert_front(node6);
  insert_front(node7);

  print_entries_all();
  free_list();
}

//

void test_insert_order(){
  printf("====================================================================\n");
  printf("TESTING INSERT ORDER...\n");

  struct song_node * node1 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node1 -> name = "make a man out of you"; node1 -> artist = "adonny osmond";

  struct song_node * node2 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node2 -> name = "chandelier"; node2 -> artist = "acsia";

  struct song_node * node3 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node3 -> name = "how far ill go"; node3 -> artist = "ablin manuel miranda";

  struct song_node * node4 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node4 -> name = "legends never die"; node4 -> artist = "aagainst the current";

  struct song_node * node5 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node5 -> name = "look what you made me do"; node5 -> artist = "ataylor swift";

  struct song_node * node6 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node6 -> name = "you belong with me"; node6 -> artist = "ataylor swift";

  struct song_node * node7 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node7 -> name = "test1"; node7 -> artist = "at";

//this code doesnt create a seg fault when the first 5 nodes are inserted using insert_front
//instead the print_list will go through an infinite loop
  insert_front(node1);
  insert_order(node2);
  insert_order(node3);
  insert_order(node4);
  insert_order(node5);
  
  insert_order(node6);
  insert_order(node7);
		      

    print_entries_all();
  free_list();
  printf("freeee\n");
  //print_entries_all();
}
