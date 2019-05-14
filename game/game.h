#ifndef HEADER_GAME
#define HEADER_GAME

#include "../core/app_mem.h"

namespace Dodger {
  namespace Game {
    bool Initialize(Dodger::AppMem *mem);
    bool Update(Dodger::AppMem *mem);
    bool Shutdown(Dodger::AppMem *mem);
  }
}

#endif
