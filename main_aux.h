#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int numOfHeapsFromUser;
bool check_validity(int numOfHeaps, int start, int end);

bool chaeck_validity_positive(int size);

void end_game(int turn);

int * start_game();

void print_status(int *heaps, int round);

void graph_status(int *heaps);

void player_turn(int *heaps);
