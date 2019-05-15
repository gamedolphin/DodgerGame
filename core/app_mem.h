#ifndef HEADER_APPMEM
#define HEADER_APPMEM

#include "../window/window.h"
#include "../renderer/renderer.h"
#include "../game/game.h"
#include <SDL2/SDL.h>

namespace Dodger {
  struct AppMem {
    Dodger::Window::WindowConfig windowConfig;
    Dodger::Renderer::RenderObject rootObject;
    Dodger::Game::GameMemory gameMemory;
    SDL_Event currentEvent;
    bool quit = false;
  };
}

#endif
