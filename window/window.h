#ifndef HEADER_WINDOW
#define HEADER_WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#define int16 uint16_t

namespace Dodger {
  namespace Window {

    struct WindowConfig {
      int16 width;
      int16 height;
      char* title;
      SDL_Window* window = NULL;
      SDL_Surface* screenSurface = NULL;
    };

    SDL_SysWMinfo GetPlatformInfo(WindowConfig *config);

    bool Initialize(WindowConfig *config);
    bool Update(WindowConfig *config);
    bool Shutdown(WindowConfig *config);
  }
}

#endif
