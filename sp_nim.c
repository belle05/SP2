#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void create_game(){

}

bool check_if_empty(int heaps){

}



void reduce_heaps(int *heaps, int heapIndex, int toRemove){
	heaps[heapIndex] = 	heaps[heapIndex] - toRemove;
}

void computer_turn(int *heaps){
	int heapIndex;
	int toRemove;


	printf("Computer takes %d objects from heap %d.\n", toRemove, heapIndex);
	reduce_heaps(heaps, heapIndex, toRemove);
}
