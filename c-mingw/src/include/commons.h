/*
  SDL C MinGW64 Template
  
  Copyright (C) 2022 Fredy Rogez (@FredyRogez)
  
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  
  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:
  
  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.	 
  2. Altered source versions must be plainly marked as such, and must not
     be misrepresented as being the original software.	 
  3. This notice may not be removed or altered from any source distribution.
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
// #include "SDL2/SDL_ttf.h"
// #include "SDL2/SDL_mixer.h"
// #include "SDL2/SDL_net.h"

// MACROS
#define MIN(a,b) ((a)<=(b)?a:b)
#define MAX(a,b) ((a)>=(b)?a:b)

// GAME
#define GAME_VERSION "1.0.0"
#define GAME_NAME "My Game"
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

typedef struct Game
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *icon;
    bool running;
} Game;
