#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "main_aux.h"
//Check if all the heaps are empty
bool check_if_empty(int *heaps){
        int sum=0;
        for (int i = 1; i< numOfHeapsFromUser; i++) {
                sum += heaps[i];
        }
        if (sum==0) {
                return true;
        }
        return false;

}

//Reduce heaps at heapIndex by toRemove
void reduce_heaps(int *heaps, int heapIndex, int toRemove){
        heaps[heapIndex] =      heaps[heapIndex] - toRemove;
}

int calculate_s_nim(int *heaps) {
        int s_nim = 0;
        for (int i = 0; i< numOfHeapsFromUser; i++) {
                s_nim ^= heaps[i];
        }
        return s_nim;
}

void computer_turn(int *heaps){
        int toRemove;
        int s_nim = calculate_s_nim(heaps);
        int min_diff = 999999;
        int tmp_i = 0;
        int min_i = 0;
        //If nim-sum is zero, remove 1 from minimal heap
        if (s_nim == 0) {
        		//Find a heap the it's size is bigger than 0
                for (int z = 0; z<numOfHeapsFromUser;z++){
                        if (heaps[z] >0) {
                                min_i = z;
                                break;
                        }
                }
                //find minimal positive heap
                for (int i = min_i; i<numOfHeapsFromUser; i++) {
                        if (heaps[i] < heaps[min_i] && (heaps[i] > 0)) {
                                min_i = i;
                        }
                }
                toRemove = 1;
        } else {
        		//find minimal positive nim-sum heap and decrease it's size
        		//so it's nim-sum will be zero.
                for (int l = 0; l<numOfHeapsFromUser; l++) {
                        tmp_i = heaps[l] - (heaps[l]^s_nim);
                        if (tmp_i >0 && tmp_i < min_diff && (heaps[l] >0)) {
                                min_diff = tmp_i;
                                min_i = l;
                        }
                }
                toRemove = min_diff;
        }
        printf("Computer takes %d objects from heap %d.\n", toRemove, min_i+1);
        reduce_heaps(heaps, min_i, toRemove);
}
