#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>


void main(){
  srand(time(NULL));
  //Populates the list with test data
    //populate();


    // insert_song("make a man out of you", "donny osmond");
    //print_entries_all();

    //test_ll_functions();
    //test_insert_front();
  test_insert_order();
  //test_find_element_song();
  //test_first_element_artist();
  test_random_element();
}
