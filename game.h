#ifndef GAME_H
#define GAME_H
#include <stdbool.h>

typedef enum {
    O, X, EMPTY
}Tile;

typedef enum {
    PLAYER_TURN, ROBOT_TURN, PLAYER_WIN, ROBOT_WIN, DRAW, NOT_OVER
}GameState;

typedef struct {
    int rows;
    int columns;
    Tile** tiles;
    GameState state;
}Game;


Game* createGame();

void destroyGame(Game* game);

void changeTile(Game* game, int row, int column, Tile tile);

void robotTurn(Game* game);

bool isOver(Game* game);

#endif // GAME_H
