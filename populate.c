


//struct song_node *linked_list = (struct song_node*)calloc(1, sizeof(struct song_node)); //will point to the first node

char * name = "I'll make a man out of you";
char * artist = "Donny Osmond";
struct song_node * linked_list = insert_front( (struct song_node*)calloc(1, sizeof(struct song_node)), name, artist);
  //
  // linked_list->name = name;
  // linked_list->artist = artist;
	linked_list=insert_song(linked_list, "I'll hi", artist);
	linked_list=insert_song(linked_list, "asfk", artist);
  

/*
  linked_list=insert_song(linked_list, "Chandelier", "Sia");
  linked_list=insert_song(linked_list, "How Far I'll Go", "Lin-Manuel Miranda");
  linked_list=insert_song(linked_list, "Legends Never Die", "Against The Current");
  linked_list=insert_song(linked_list, "Look What You Made Me Do", "Taylor Swift");
  print_list(linked_list);
*/
