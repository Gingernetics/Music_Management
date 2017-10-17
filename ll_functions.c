
//adds a node to the front of the list with the given value
//returns a pointer to the beginning of the list
struct song_node * insert_front(struct song_node * front, char * song_name, char * song_artist){
  struct song_node *new = (struct song_node*)calloc(1, sizeof(struct song_node));
  new -> name = song_name;
  new -> artist = song_artist;
  new -> next = front;
  return new;
}

//Insert nodes in order
struct song_node * insert_between(struct song_node * before, 
				struct song_node * current, 
				struct song_node * after);


//prints out the list, with song name and its artist
void print_list(struct song_node * current){
  while(current->next){
    printf("Song Name: %s \t by:%s\n", current->name, current->artist);
    current = current->next;
  }
}

//Find and return a pointer to a node based on artist and song name
struct song_node * find_element(char * song_name, 
				char * song_artist);

//Find and return a pointer to the first song of an artist based on artist name
struct song_node * first_element(char * song_artist);

//Return a pointer to random element in the list.
struct song_node * random_element();

//Free node
void free_node(struct song_node * element);

//frees all the nodes in the list
//returns a pointer to the beginning of the list
void free_list(struct song_node * list){
  struct song_node *temp;
  while(list->next){
    temp = list -> next;
    free(list);
    list = temp;
  }
}
