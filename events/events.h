#ifndef HEADER_EVENTS
#define HEADER_EVENTS

#include <SDL2/SDL.h>

namespace Dodger {
  namespace Events {
    int PollEvents(SDL_Event *e) {
      return SDL_PollEvent(e);
    }
  }
}

#endif
