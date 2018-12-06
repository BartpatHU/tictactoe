#include "engine.h"
#include "game.h"
#include <SDL2/SDL.h>

typedef unsigned int uint32;

int main(int argc, char** argv){

const int FPS = 60;
const int frameDelay = 1000/FPS;

uint32 frameStart;
int frameTime;

init("TicTacToe", 600, 600);

Game* game = createGame(3, 3);

while(isrunning()){

    frameStart = SDL_GetTicks();

    handleEvents(game);
    update(game);
    render(game);

    frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime){
        SDL_Delay(frameDelay-frameTime);
    }
}

destroy();

return 0;
}
