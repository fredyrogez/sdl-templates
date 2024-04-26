/*  
  SDL C++ Visual Studio Template

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

#pragma once
#include <iostream>

const std::string game_name{ "My Game" };
const int window_width{ 800 };
const int window_height{ 600 };
const Uint32 window_flags{ SDL_WINDOW_SHOWN };

const std::string assets_dir{ "assets/" };
const std::string texture_file{ assets_dir + "texture.png" };
