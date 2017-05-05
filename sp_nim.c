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

int calculate_s_nim(int *heaps) {
	int s_nim = 0;
	for (unsigned i = 0; i< sizeof(heaps); i++) {
		s_nim ^= heaps[i];
	}
	return s_nim;
}

void computer_turn(int *heaps){
	int heapIndex;
	int toRemove;
	int s_nim = caclculate_s_nim(heaps);
	int min_diff = 999999;
	int tmp_i = 0;
	int min_i = 0;
	for (unsigned i = 0; i< sizeof(heaps); i++) {
		tmp_i = heaps[i] - (heaps[i]^s_nim);
		if (tmp_i >0 && tmp_i < min_diff) {
			min_diff = tmp_i;
			min_i = i;
		}
	}
	printf("Computer takes %d objects from heap %d.\n", toRemove, heapIndex);
	reduce_heaps(heaps, heapIndex, toRemove);
}
