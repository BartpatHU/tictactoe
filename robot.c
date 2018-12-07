#include "robot.h"
#include <time.h>
#include <stdlib.h>

void ready(){
    srand(time(NULL));
}

void turn(Game* game){
    int rows = game->rows;
    int columns = game->columns;
    int rowTurn = rand()%rows;
    int columnTurn = rand()%columns;
    if(game->tiles[rowTurn][columnTurn] == EMPTY){
        game->tiles[rowTurn][columnTurn] = O;
    }else{
        turn(game);
    }
}
