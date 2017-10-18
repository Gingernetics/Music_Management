#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include <time.h>

srand(time(NULL)); 

void main(){

    //Table organized songs by first letter of author
    struct song_node * alph_table[26];

    


    //First node of the linked list
    HEAD = (struct song_node*)calloc(1, sizeof(struct song_node));

    //Populates the list with test data
    populate();




    printf("\n\n freeing list... ");

    linked_list = free_list(linked_list);
    if(linked_list){
        print_list(linked_list);
    }
}
