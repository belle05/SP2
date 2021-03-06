  /*
 *  Created on: Mar 27, 2017
 *      Author: nlevy
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sp_nim.h"
#include "main_aux.h"
#include "SPBufferset.h"

int main()
{
        SP_BUFF_SET();
        int turn = 0;
        int round = 1;

        //Game starts
        int *heaps = start_game();
        if (heaps==NULL){
                return 0;
        }
        //Game will continue until there's a winner
        while(!(check_if_empty(heaps))){
                print_status(heaps, round);
                if (turn == 1) {
                        graph_status(heaps);
                        player_turn(heaps);
                } else {
                        computer_turn(heaps);
                }
                if (turn == 0) turn = 1;
                else turn = 0;
                round++;
        }
        end_game(turn);
}
