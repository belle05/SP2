#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "sp_nim.h"
#define NUM_OF_HEAPS 32
int numOfHeapsFromUser;
//Checks if numOfHeaps provided is between start and end
bool check_validity(int numOfHeaps, int start, int end){
        if(numOfHeaps>end || numOfHeaps < start) {
                        return 0;
        }
        return 1;

}

//Checks if size is positive
bool check_validity_positive(int size){
        if (size<=0){
                return 0;
        }
        return 1;
}

//Prints the winner
void end_game(int turn) {
        if (turn==1){
                printf("Computer wins!\n");
        } else {
                printf("You win!\n");
        }
}

//Creates heaps by the user's requests
int * start_game(){
        printf("Enter the number of heaps:\n");
        scanf ("%d", &numOfHeapsFromUser);
        if(!(check_validity(numOfHeapsFromUser, 1, 32))){
                        printf("Error: the number of heaps must be between 1 and 32.\n");
                        return NULL;
        }

        //Inits heaps to zeros
        static int heapSizes[NUM_OF_HEAPS];
        for (int i = 0; i<NUM_OF_HEAPS;i++) {
                heapSizes[i] = 0;
        }
        //Initiate the heaps' sizes to the user's request
        printf("Enter the heap sizes:\n");
        for(int i=0; i<numOfHeapsFromUser; i++) {
                scanf ("%d", &heapSizes[i]);
                if (!(check_validity_positive(heapSizes[i]))) {
                        printf("Error: the size of heap %d should be positive.\n", i+1);
                        return NULL;
                }
        }
        return heapSizes;
}

//Print game status (textual)
void print_status(int *heaps, int round){
        printf("In turn %d heap sizes are: ",round);
        for (int i = 0; i<numOfHeapsFromUser;i++) {
                if (i == numOfHeapsFromUser-1) {
                        printf("h%d=%d.\n",i+1,heaps[i]);
                }
                else {
                        printf("h%d=%d ",i+1,heaps[i]);
                }
        }

}

//Print game status (graphic)
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
                                if (l == numOfHeapsFromUser-1) {
                                        printf("*");
                                }
                                else {
                                        printf("*\t");
                                }
                        }
                        else {
                                printf(" \t");
                        }
                }
                printf("\n");
        }
}

//Let the user pick heap and how much to decrease it's size
void player_turn(int *heaps){
        int heapIndex;
        int toRemove;
        bool isValid = false;
        printf("Your turn: please enter the heap index and the number of removed objects.\n");
        //Request the user's input until it is valid
        while(!isValid) {
                scanf ("%d", &heapIndex);
                scanf ("%d", &toRemove);
                heapIndex--;
                isValid = (check_validity(heapIndex, 0, numOfHeapsFromUser)) && (check_validity(toRemove, 1, heaps[heapIndex]));

                if (isValid) {
                        printf("You take %d objects from heap %d.\n", toRemove, heapIndex+1);
                        reduce_heaps(heaps, heapIndex, toRemove);
                } else {
                        printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
                }
        }

}

