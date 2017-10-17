//This file is designated for core linked list functions
struct song_node{
	char * name;
	char * artist;
  struct song_node *next;
};

//Insert nodes at the front
struct song_node * insert_front(struct song_node * front, 
				char * song_name, 
				char * song_artist);

//Insert nodes in order
struct song_node * insert_between(struct song_node * before, 
				struct song_node * current, 
				struct song_node * after);


//Print the entire list
void print_list(struct song_node * current);

//Find and return a pointer to a node based on artist and song name
struct song_node * find_element(char * song_name, 
				char * song_artist);

//Find and return a pointer to the first song of an artist based on artist name
struct song_node * first_element(char * song_artist);

//Return a pointer to random element in the list.
struct song_node * random_element();

//Free node
void free_node(struct song_node * element);

//Free the entire list
void free_list(struct song_node * list);
