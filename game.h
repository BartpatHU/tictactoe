#ifndef GAME_H
#define GAME_H

typedef enum {
    O, X, EMPTY
}Tile;

typedef struct {
    int rows;
    int columns;
    Tile** tiles;
}Game;


Game* createGame();

void destroyGame(Game* game);

void changeTile(Game* game, int row, int column, Tile tile);

#endif // GAME_H
