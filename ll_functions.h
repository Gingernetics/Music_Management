struct song_node{
	char * name;
	char * artist;
  struct song_node *next;
};

void print_list(struct song_node * current);

struct song_node * insert_front(struct song_node * front, char * song_name, char * song_artist);
struct song_node * insert_between(struct song_node * before, struct song_node * current, struct song_node * after);
struct song_node * find_song(char * song_name);
struct song_node * find_artist(char * song_artist);
struct song_node * random_song();
struct song_node * free_list(struct song_node * list);


struct song_node * insert_song(struct song_node * current, char * song_name, char * song_artist);
