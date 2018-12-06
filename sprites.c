#include "sprites.h"
#include <SDL2/SDL_image.h>

SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer){
    SDL_Surface* surf = IMG_Load(fileName);
    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return text;
}
