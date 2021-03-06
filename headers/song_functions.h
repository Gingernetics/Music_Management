//This file is designated for wrapper functions
struct song_node{
	char * name;
	char * artist;
  struct song_node *next;
};

//Table organized songs by first letter of author
struct song_node * alph_table[26];

//Populates the program with sample titles and artists
void populate();

//Add song nodes
struct song_node * insert_song(	char * song_name, char * song_artist);

//Search for and return pointer to song given song and artist name
struct song_node * find_song(char * song_name, char * song_artist);

//Search for and return pointer to artist
struct song_node * find_artist(char * song_artist);

//
void print_node(struct song_node* node);

//Print out all the entries under a certain letter
void print_entries_char(char character);

//Print out all the songs of a certain artist
void print_entries_artist(char * song_artist);

//Print
void print_entries_all();

//Shuffle - print out a series of randomly chosen songs
void random_song(int quantity);

//Delete a song
void delete_song(char * song_name, char * song_artist);

//Delete all the nodes
void clear_program();
