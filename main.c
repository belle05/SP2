 /*
 *  Created on: Mar 27, 2017
 *      Author: nlevy
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <sp_nim.h>
#include <main_aux.h>
#include "SPBufferset.h"

int main()
{
	SP_BUFF_SET();
	int *heapSizes;
	int turn = 0;
	int round = 0;

	int *heaps = start_game();
	if (heaps==NULL){
		return 0;
	}
	while(check_if_empty(heaps)){
		print_status(heaps, round);
		if (turn == 1) {
			graph_status(heaps);
			player_turn(heaps);
		} else {
			computer_turn(heaps);
		}
		if (turn == 0) turn = 1;
		else (turn == 1) turn = 0;
		round++;
	}
	end_game(turn);
}

