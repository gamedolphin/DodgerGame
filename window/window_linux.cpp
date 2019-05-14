#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

SDL_SysWMinfo Dodger::Window::GetPlatformInfo(WindowConfig *config) {
  SDL_SysWMinfo wmi;
  SDL_VERSION(&wmi.version);
  // TODO: Handle case where this returns false
  SDL_GetWindowWMInfo(config->window, &wmi);
  return wmi;
}

bool Dodger::Window::Initialize(Dodger::Window::WindowConfig *config) {

  SDL_Window* window = NULL;
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    return false;
  }
  else {
    //Create window
     window = SDL_CreateWindow( config->title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, config->width, config->height, SDL_WINDOW_SHOWN );
    if( window == NULL ) {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
      return false;
    }
  }

  config->window = window;
  return true;
}

bool Dodger::Window::Update(Dodger::Window::WindowConfig *config) {
  config->screenSurface = SDL_GetWindowSurface( config->window );
  //Fill the surface white
  SDL_FillRect( config->screenSurface, NULL, SDL_MapRGB( config->screenSurface->format, 0xFF, 0xFF, 0x00 ) );
  //Update the surface
  SDL_UpdateWindowSurface( config->window );
  //Wait two seconds
  return true;
}

bool Dodger::Window::Shutdown(Dodger::Window::WindowConfig *config) {

  SDL_DestroyWindow( config->window );

  SDL_Quit();
  return true;
}
