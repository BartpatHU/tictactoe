#ifndef ENGINE_H
#define ENGINE_H
#include <stdbool.h>
#include "game.h"

void init();
void handleEvents(Game* game);
void update(Game* game);
void render(Game* game);

void destroy();

bool isrunning();

#endif // ENGINE_H
