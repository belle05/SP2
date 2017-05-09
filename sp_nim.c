#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "main_aux.h"
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
        if (s_nim == 0) {
                toRemove = 1;
                for (int i = 1; i<numOfHeapsFromUser; i++) {
                        if (heaps[i] < heaps[min_i]) {
                                min_i = i;
                        }
                }
        } else {
                for (int i = 0; i<numOfHeapsFromUser; i++) {
                        tmp_i = heaps[i] - (heaps[i]^s_nim);
                        if (tmp_i >0 && tmp_i < min_diff) {
                                min_diff = tmp_i;
                                min_i = i;
                        }
                }
                toRemove = min_diff;
        }
        printf("Computer takes %d objects from heap %d.\n", toRemove, min_i+1);
        reduce_heaps(heaps, min_i, toRemove);
}
