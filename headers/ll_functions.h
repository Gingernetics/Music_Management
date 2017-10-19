//Insert nodes at the front
struct song_node * insert_front(struct song_node * new_song);

//Insert nodes in order
struct song_node * insert_order(struct song_node * new_song);

//Print the entire list
void print_list(struct song_node * current);

//Find and return a pointer to a node based on artist and song name
struct song_node * find_element_song(char * song_name, char * song_artist);

//Find and return a pointer to the first song of an artist based on artist name
struct song_node * first_element_artist(char * song_artist);

//Return a pointer to random element in the list.
struct song_node * random_element();

//Free node
void free_node(struct song_node * element);

//Free the entire list
void free_list();
