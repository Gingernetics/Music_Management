#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ll_functions.h"
#include "headers/song_functions.h"
#include "headers/test_functions.h"
#include <time.h>


void main(){
  time_t t;
  srand((unsigned)time(&t));
  test_ll_functions();
}
