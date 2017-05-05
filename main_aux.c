#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool check_validity(int numOfHeaps, int start, int end){
	if(numOfHeaps>end || numOfHeaps < start) {
			return 0;
	}
	return 1;

}

bool chaeck_validity_positive(int size){
	if (size<=0){
		return 0;
	}
	return 1;
}

void end_game(int turn) {
	if (turn==0){
		printf("Computer wins!\n");
	} else {
		printf("You win!\n")
	}
}

int * start_game(){
	int numOfHeaps;

	printf("Enter the number of heaps:\n");
	scanf ("%d", &numOfHeaps);
	if(!(check_validity(numOfHeaps, 1, 32)){
			printf("Error: the number of heaps must be between 1 and 32.\n");
	}

	int heapSizes[numOfHeaps];
	printf("Enter the heap sizes:\n");
	for(int i=0; i<numOfHeaps; i++) {
		scanf ("%d", &heapSizes[i]);
		if (!(check_validity_positive(heaps[i])) {
			printf("Error: the size of heap %d should be positive.\n", heapSizes[i]);
			return NULL;
		}
	}
	return heapSizes;
}

void print_status(int *heaps, int round){
	printf("In turn %d heap sizes are: ",round);
	for (unsigned int i = 0; i<sizeof(heaps);i++) {
		printf("h%d=%d",i,heaps[i]);
	}
	printf("\n");

}

void graph_status(int *heaps) {
	int max = 0;
	for (unsigned int i = 0; i<sizeof(heaps);i++) {
		if (heaps[i] > max) {
			max = heaps[i];
		}
	}
	for (int i = max; i>0;i--) {
		for (unsigned int l = 0; i<sizeof(heaps);l++) {
			if (heaps[l] >=i ) {
				if (l == sizeof(heaps)-1) {
					printf("*");
				}
				else {
					printf("*\t");
				}
			}
			else {
				printf("\t");
			}
		}
		printf("\n");
	}
}

void player_turn(int *heaps){
	int heapIndex;
	int toRemove;
	bool isValid = False;

	while(!isValid) {
		printf("Your turn: please enter the heap index and the number of removed objects.\n");
		scanf ("%d", &heapIndex);
		scanf ("%d", &toRemove);

		isValid = (check_validity(heapIndex, 0, sizeof(heaps))) && (check_validity(toRemove, 1, heaps[heapIndex])))

		if (isValid) {
			printf("You take %d objects from heap %d.\n", toRemove, heapIndex);
			reduce_heaps(heaps, heapIndex, toRemove);
		} else {
			printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
		}
	}

}
