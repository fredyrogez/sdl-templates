/*
  SDL C MinGW64 Template
  
  Copyright (C) 2024 Fredy Rogez (@FredyRogez)
  
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

#include "commons.h"

Game game;

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    game.running = true;
    game.window = NULL;
    game.renderer = NULL;
    game.texture = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_RENDERER_PRESENTVSYNC);
	
	#ifdef _DEBUG
	printf(">> DEBUG MODE");
	#endif

    game.window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (game.window == NULL)
    {
        printf("ERROR : SDL_CreateWindow");
        exit(1);
    }

    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);
    if (game.renderer == NULL)
    {
        printf("ERROR : SDL_CreateRenderer");
        exit(1);
    }

    SDL_Surface *surface = IMG_Load("assets/SDL_logo.png");
    game.texture = SDL_CreateTextureFromSurface(game.renderer, surface);
    SDL_FreeSurface(surface);

    while (game.running)
    {
        // EVENTS
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                game.running = false;
                break;
            }
        }

        // UPDATE
        // ...


        // DRAW
        SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
        SDL_RenderClear(game.renderer);
        SDL_RenderCopy(game.renderer, game.texture, NULL, NULL);
        SDL_RenderPresent(game.renderer);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyTexture(game.texture);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
    return 0;
}
