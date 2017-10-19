#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>


void main(){
    srand(time(NULL)); 

    //Table organized songs by first letter of author
    struct song_node * table[26];

    //Populates the list with test data
    populate();

}
