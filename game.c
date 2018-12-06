#include "game.h"
#include <stdlib.h>

Game* createGame(int rows, int columns){
    Game* gm = malloc(sizeof(Game));
    gm->tiles = malloc(sizeof(Tile*) * rows);
    for(int i = 0; i < rows; i++){
        gm->tiles[i] = malloc(sizeof(Tile) * columns);
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            gm->tiles[i][j] = EMPTY;
        }
    }
    gm->rows = rows; gm->columns = columns;
    return gm;
}


void destroyGame(Game* game){
    for(int i = 0; i < game->rows; i++){
        free(game->tiles[i]);
    }
    free(game->tiles);
    free(game);
}

void changeTile(Game* game, int row, int column, Tile tile){
    game->tiles[row][column] = tile;
}
