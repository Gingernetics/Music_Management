#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>


void main(){
  time_t t;
  srand((unsigned)time(&t));
  //Populates the list with test data
  //populate();
  //test_find_song();
  populate();
  random_song(20);

    // insert_song("make a man out of you", "donny osmond");
    //print_entries_all();

    //test_ll_functions();
    //test_insert_front();
/*
  test_insert_order();
  //test_find_element_song();
  //test_first_element_artist();
   test_random_element();
  test_random_element();
  test_random_element();
  test_random_element();
*/   
//  print_node(first_element_artist("aaa"));

  /*

  print_node(first_element_artist("aaa"));
  free_node(first_element_artist("aaa"));
  // print_node(first_element_artist("aaa"));
 print_node(first_element_artist("against the current"));
  free_node(first_element_artist("against the current"));
  //print_node(first_element_artist("against the current"));
  
  free_node(first_element_artist("donny osmond"));
  printf("sigh\n");
  free_node(first_element_artist("lin manuel miranda"));
  printf("sigh\n");
  free_node(first_element_artist("sia"));
  printf("sigh\n");
 free_node(first_element_artist("t"));
  printf("sigh\n");
  free_node(first_element_artist("taylor swift"));
  printf("sigh\n");
  free_node(first_element_artist("taylor swift"));
  printf("sigh\n");
  free_node(first_element_artist("taylor swift"));
  printf("sigh\n");
  free_node(first_element_artist("taylor swift"));
  printf("sigh\n");
  */
  
  //free_list();
}
