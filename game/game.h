#ifndef HEADER_GAME
#define HEADER_GAME

#include <cstdint>

namespace Dodger {

  namespace Game {

    struct GameMemory {
      uint64_t permanentStorageSpace;
      void *permanentStorage;

      uint64_t transientStorageSpace;
      void *transientStorage;
    };

    bool Initialize(GameMemory *mem);
    bool Update(GameMemory *mem);
    bool Shutdown(GameMemory *mem);

    GameMemory CreateState();
  }
}

#endif
