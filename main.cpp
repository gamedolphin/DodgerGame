#include <SDL2/SDL.h>
#include <stdio.h>
#include "window/window.h"
#include "renderer/renderer.h"
#include "core/app_mem.h"
#include "events/events.h"
#include "game/game.h"

using namespace Dodger;

int main( int argc, char* args[] ) {

  AppMem appMem;
  appMem.windowConfig = { 640, 400, "Dodger" };
  appMem.rootObject = Dodger::Renderer::CreateRoot();

  if(Window::Initialize(&appMem.windowConfig)) {

    // setup initial game
    Game::Initialize(&appMem);

    // setup bgfx renderer
    Renderer::Initialize(&appMem.windowConfig);

    while(!appMem.quit) {
      while(Events::PollEvents(&appMem.currentEvent) != 0) {
        if(appMem.currentEvent.type == SDL_QUIT) {
          appMem.quit = true;
        }
      }
      // update game world and setup render
      Game::Update(&appMem);

      // flush to screen
      Renderer::Render(&appMem.windowConfig, &appMem.rootObject);
    }
  }

  Game::Shutdown(&appMem);
  Renderer::Shutdown(&appMem.windowConfig);
  Window::Shutdown(&appMem.windowConfig);

  return 0;
}
