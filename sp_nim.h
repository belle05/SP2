#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
bool check_if_empty(int *heaps);

void reduce_heaps(int *heaps, int heapIndex, int toRemove);

int calculate_s_nim(int *heaps);

void computer_turn(int *heaps);
