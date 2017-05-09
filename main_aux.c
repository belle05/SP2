#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "sp_nim.h"
#define NUM_OF_HEAPS 32
int numOfHeapsFromUser;
bool check_validity(int numOfHeaps, int start, int end){
        if(numOfHeaps>end || numOfHeaps < start) {
                        return 0;
        }
        return 1;

}

bool check_validity_positive(int size){
        if (size<=0){
                return 0;
        }
        return 1;
}

void end_game(int turn) {
        if (turn==1){
                printf("Computer wins!\n");
        } else {
                printf("You win!\n");
        }
}

int * start_game(){
        printf("Enter the number of heaps:\n");
        scanf ("%d", &numOfHeapsFromUser);
        if(!(check_validity(numOfHeapsFromUser, 1, 32))){
                        printf("Error: the number of heaps must be between 1 and 32.\n");
        }

        static int heapSizes[NUM_OF_HEAPS];
        for (int i = 0; i<NUM_OF_HEAPS;i++) {
                heapSizes[i] = 0;
        }
        printf("Enter the heap sizes:\n");
        for(int i=0; i<numOfHeapsFromUser; i++) {
                scanf ("%d", &heapSizes[i]);
                if (!(check_validity_positive(heapSizes[i]))) {
                        printf("Error: the size of heap %d should be positive.\n", heapSizes[i]);
                        return NULL;
                }
        }
        return heapSizes;
}

void print_status(int *heaps, int round){
        printf("In turn %d heap sizes are: ",round);
        for (int i = 0; i<numOfHeapsFromUser;i++) {
                printf("h%d=%d ",i+1,heaps[i]);
        }
        printf("\n");

}

void graph_status(int *heaps) {
        int max = 0;
        for ( int i = 0; i<numOfHeapsFromUser;i++) {
                if (heaps[i] > max) {
                        max = heaps[i];
                }
        }
        for (int i = max; i>0;i--) {
                for (int l = 0; l<numOfHeapsFromUser;l++) {
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
        bool isValid = false;

        while(!isValid) {
                printf("Your turn: please enter the heap index and the number of removed objects.\n");
                scanf ("%d", &heapIndex);
                scanf ("%d", &toRemove);
                heapIndex--;
                isValid = (check_validity(heapIndex, 0, numOfHeapsFromUser)) && (check_validity(toRemove, 1, heaps[heapIndex]));

                if (isValid) {
                        printf("You take %d objects from heap %d.\n", toRemove, heapIndex);
                        reduce_heaps(heaps, heapIndex, toRemove);
                } else {
                        printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
                }
        }

}

