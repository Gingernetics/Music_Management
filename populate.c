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
  insert_song("ours", "taylor swift");
  insert_song("theirs", "taylor swift");
  insert_song("you belong with me", "taylor swift");
  insert_song("test", "t");
  insert_song("", "t");
}

void test_all_functions(){
  printf("====================================================================\n");
  printf("TESTING...\n");
  test_ll_functions();
  test_song_functions();
}

void test_song_functions(){
  printf("====================================================================\n");
  printf("TESTING SONG FUNCTIONS...\n");
  void test_insert_song();
  void test_find_song();
  void test_find_artist();
  void test_random_song();
  void test_delete_song();
  void test_clear_program();
}

void test_insert_song(){
  printf("====================================================================\n");
  printf("TESTING INSERT SONG...\n");
  populate();
  print_entries_all();
  free_list();
}

void test_find_song(){
  printf("====================================================================\n");
  printf("TESTING FIND SONG...\n");
  populate();

  print_node(find_song("make a man out of you", "donny osmond"));
  print_node(find_song("chandelier", "sia"));
  print_node(find_song("how far ill go", "lin manuel miranda"));
  print_node(find_song("legends never die", "against the current"));
  print_node(find_song("look what you made me do", "taylor swift"));
  print_node(find_song("ours", "taylor swift"));
  print_node(find_song("theirs", "taylor swift"));
  print_node(find_song("you belong with me", "taylor swift"));
  print_node(find_song("test", "t"));
  print_node(find_song("", "t"));

  free_list();
}

void test_find_artist(){
  printf("====================================================================\n");
  printf("TESTING FIND ARTIST...\n");
  populate();

  print_node(find_artist("donny osmond"));
  print_node(find_artist("sia"));
  print_node(find_artist("lin manuel miranda"));
  print_node(find_artist("against the current"));
  print_node(find_artist("taylor swift"));
  print_node(find_artist("test", "t"));

  free_list();

}
void test_random_song(){
  printf("====================================================================\n");
  printf("TESTING RANDOM SONG...\n");
  populate();

  random_song(10);

  free_list();
}
void test_delete_song(){
  printf("====================================================================\n");
  printf("TESTING DELETE SONG...\n");
  populate();
  delete_song("make a man out of you", "donny osmond");
  delete_song("chandelier", "sia");
  delete_song("how far ill go", "lin manuel miranda");
  delete_song("legends never die", "against the current");
  delete_song("look what you made me do", "taylor swift");
  delete_song("ours", "taylor swift"))
  delete_song("theirs", "taylor swift");
  delete_song("you belong with me", "taylor swift");
  delete_song("test", "t"));
  delete_song("", "t"));
  print_entries_all();
}
void test_clear_program(){
  printf("====================================================================\n");
  printf("TESTING CLEAR PROGRAM...\n");

  populate();
  free_list();
  print_entries_all();
}

void test_ll_functions(){
  printf("====================================================================\n");
  printf("TESTING LL FUNCTIONS...\n");
  test_insert_front();
  test_insert_order();
  test_find_element_song();
  test_first_element_artist();
  test_random_element();
  test_find_song();
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
  print_entries_all();
}

//

void test_insert_order(){
  printf("====================================================================\n");
  printf("TESTING INSERT ORDER...\n");

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

  struct song_node * node8 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node8 -> name = "ours"; node8 -> artist = "taylor swift";

  struct song_node * node9 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node9 -> name = "theirs"; node9 -> artist = "taylor swift";

  struct song_node * node10 = (struct song_node*)calloc(1, sizeof(struct song_node));
  node10 -> name = "aaaasdf"; node10 -> artist = "aaa";

  insert_order(node1);
  insert_order(node2);
  insert_order(node3);
  insert_order(node4);
  insert_order(node5);
  insert_order(node6);
  insert_order(node7);
  insert_order(node8);
  insert_order(node9);
  insert_order(node10);

  print_entries_all();
  free_list();
  print_entries_all();
}

void test_find_element_song(){
  printf("====================================================================\n");
  printf("TESTING FIND ELEMENT SONG...\n");

  populate();

  print_node(find_element_song("make a man out of you", "donny osmond"));
  print_node(find_element_song("asd", "donny osmond"));
  print_node(find_element_song("make a man out of you", "asdf"));
  print_node(find_element_song("asd", "asdf"));
  print_node(find_element_song("theirs", "taylor swift"));
  print_node(find_element_song("ours", "taylor swift"));
  print_node(find_element_song("look what you made me do", "taylor swift"));

  free_list();
}

void test_first_element_artist(){
  printf("====================================================================\n");
  printf("TESTING FIRST ELEMENT ARTIST...\n");

  populate();

  print_node(first_element_artist("donny osmond"));
  print_node(first_element_artist("taylor swift"));
  print_node(first_element_artist("lin manuel miranda"));
  print_node(first_element_artist("sia"));
  print_node(first_element_artist("t"));
  print_node(first_element_artist("against the current"));

  free_list();
}

void test_random_element(){
  printf("====================================================================\n");
  printf("TESTING RANDOM ELEMENT...\n");

  populate();

  int i = 10;
  while(i){
    print_node(random_element());
    i--;
  }
  free_list();
}

void test_find_song(){
  printf("====================================================================\n");
  printf("TESTING FIND SONG...\n");

  populate();

  print_node(find_song("make a man out of you", "donny osmond"));
  print_node(find_song("chandelier", "sia"));
  print_node(find_song("how far ill go", "lin manuel miranda"));
  print_node(find_song("legends never die", "against the current"));
  print_node(find_song("look what you made me do", "taylor swift"));
  print_node(find_song("ours", "taylor swift"));
  print_node(find_song("theirs", "taylor swift"));
  print_node(find_song("you belong with me", "taylor swift"));
  print_node(find_song("test", "t"));
  print_node(find_song("", "t"));

  free_list();
}
