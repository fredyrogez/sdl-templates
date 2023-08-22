/*
  SDL C++ Visual Studio Template

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

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_net.h"
#include "SDL_ttf.h"

#include "main.h"

int main(int argc, char* args[])
{
    bool game_running=true;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Window* window = SDL_CreateWindow(game_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, window_flags);
    if (!window)
    {
        game_running = false;
        std::cout << "ERROR : SDL_CreateWindow" << std::endl;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        game_running = false;
        std::cout << "ERROR : SDL_CreateRenderer" << std::endl;
    }

    SDL_Surface* surface = IMG_Load(texture_file.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    while (game_running)
    {
        // Events
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT: // Close window
                game_running = false;
                break;
            }
        }

        // Update
        // ...


        // Draw
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Delay(1);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}