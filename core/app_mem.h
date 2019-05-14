#ifndef HEADER_APPMEM
#define HEADER_APPMEM

#include "../window/window.h"
#include "../renderer/renderer.h"
#include <SDL2/SDL.h>

namespace Dodger {
  struct AppMem {
    Dodger::Window::WindowConfig windowConfig;
    Dodger::Renderer::RenderObject rootObject;
    SDL_Event currentEvent;
    bool quit = false;
  };
}

#endif
