#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"


void populate(){
  //Adding many, many songs
  linked_list=insert_song(linked_list, "I'll make a man out of you", "Donny Osmond");
  linked_list=insert_song(linked_list, "Chandelier", "Sia");
  linked_list=insert_song(linked_list, "How Far I'll Go", "Lin-Manuel Miranda");
  linked_list=insert_song(linked_list, "Legends Never Die", "Against The Current");
  linked_list=insert_song(linked_list, "Look What You Made Me Do", "Taylor Swift");
}
