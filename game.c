#include "game.h"
#include <stdlib.h>
#include "robot.h"
#include <stdbool.h>

bool isDraw(Game* game);
bool inRow(Game* game, Tile tile);
bool coordExist(Game* game, int row, int column);

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
    gm->state = ROBOT_TURN;
    ready();
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

void robotTurn(Game* game){
    turn(game);
}

bool isOver(Game* game){
    if(isDraw(game)){
        game->state = DRAW;
        return true;
    }else{
        if(inRow(game, X)){
            game->state = PLAYER_WIN;
            return true;
        }else if(inRow(game, O)){
            game->state = ROBOT_WIN;
            return true;
        }
    }
    return false;
}


bool isDraw(Game* game){
    for(int i = 0; i < game->rows; i++){
        for(int j = 0; j < game->columns; j++){
            if(game->tiles[i][j] != EMPTY){
                return false;
            }
        }
    }
    return true;
}


bool inRow(Game* game, Tile tile){
    for(int i = 0; i < game->rows; i++){
        for(int j = 0; j < game->columns; j++){
            if(game->tiles[i][j] == tile){
                //right
                if(coordExist(game, i, j+2)){
                    if(game->tiles[i][j+1] == tile && game->tiles[i][j+2] == tile){
                        return true;
                    }
                }
                //down
                if(coordExist(game, i+2, j)){
                    if(game->tiles[i+1][j] == tile && game->tiles[i+2][j] == tile){
                        return true;
                    }
                }
                //right&&down
                if(coordExist(game, i+2, j+2)){
                    if(game->tiles[i+1][j+1] == tile && game->tiles[i+2][j+2] == tile){
                        return true;
                    }
                }
                //right&&up
                if(coordExist(game, i-2, j+2)){
                    if(game->tiles[i-1][j+1] == tile && game->tiles[i-2][j+2] == tile){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool coordExist(Game* game, int row, int column){
    if(row >= 0 && row < game->rows && column >= 0 && column < game->columns){
        return true;
    }else{
        return false;
    }
}
