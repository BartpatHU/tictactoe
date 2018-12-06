#include "engine.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "sprites.h"

#define TILE_WIDTH 200
#define TILE_HEIGHT 200

void renderTiles(SDL_Renderer* renderer, Game* game);
void renderTile(SDL_Renderer* renderer, int row, int column, Tile tile);

SDL_Window* window;
SDL_Renderer* renderer;
bool running = false;
SDL_Texture* bgText;
SDL_Texture* oText;
SDL_Texture* xText;

void init(const char* title, int width, int height){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0){
        printf("SDL initialized\n");
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
        if(window == NULL){
            printf("Couldn't create window\n");
            return;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(renderer == NULL){
            printf("Couldn't create renderer\n");
            return;
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        bgText = loadTexture("bg.jpg", renderer);
        oText = loadTexture("o.png", renderer);
        xText = loadTexture("x.png", renderer);

        if(bgText == NULL || oText == NULL || xText == NULL){
            printf("Textures couldn't be loaded\n");
            return;
        }

        running = true;
    }
}


void handleEvents(Game* game){
    SDL_Event event;
    //there is some event
    if (SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                SDL_Quit();
            break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button){
                    case SDL_BUTTON_LEFT:
                    printf("X:%d\tY:%d\n", event.motion.x, event.motion.y);
                    changeTile(game, event.motion.x/TILE_WIDTH, event.motion.y/TILE_HEIGHT, X);
                    break;
                }
            break;
        }
    }
}


void update(Game* game){

}


void destroy(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void render(Game* game){
    SDL_RenderClear(renderer);
    //render
    SDL_RenderCopy(renderer, bgText, NULL, NULL);
    renderTiles(renderer, game);
    SDL_RenderPresent(renderer);
}


bool isrunning(){
    return running;
}

void renderTiles(SDL_Renderer* renderer, Game* game){
    for(int i = 0; i < game->rows; i++){
        for(int j = 0; j < game->columns; j++){
            renderTile(renderer, i, j, game->tiles[i][j]);
        }
    }
}

void renderTile(SDL_Renderer* renderer, int row, int column, Tile tile){
    if(tile != EMPTY){
        SDL_Rect rect;
        rect.w = TILE_WIDTH/2,
        rect.h = TILE_HEIGHT/2;
        rect.x = row*TILE_WIDTH + TILE_WIDTH/2 - TILE_WIDTH/4;
        rect.y = column*TILE_HEIGHT + TILE_HEIGHT/2 - TILE_HEIGHT/4;
        if(tile == O){
            SDL_RenderCopy(renderer, oText, NULL, &rect);
        }else{
            SDL_RenderCopy(renderer, xText, NULL, &rect);
        }
    }
}
