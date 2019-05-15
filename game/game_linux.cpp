#include "game.h"
#include <stdlib.h>
#include <sys/mman.h>
#include <err.h>
#include <errno.h>
#include "../core/utils.h"

namespace Dodger {
  namespace Game {

    uint32_t RESERVED_SPACE_PERM = Megabytes((uint64_t)64);
    uint32_t RESERVED_SPACE_TRANS = Gigabytes((uint64_t)2);
    #if DEBUG
    void* RESERVED_ADD_PERM = (void*)1000;
    #else
    void* RESERVED_ADD_PERM = nullptr;
    #endif

    struct GameState {
      int PX;
      int PY;
    };

    bool Initialize(GameMemory *mem) {
      GameState* state = (GameState*)mem->permanentStorage;
      return true;
    }

    bool Update(GameMemory *mem) {
      GameState* state = (GameState*)mem->permanentStorage;

      state->PX = 0;
      state->PY = 0;
      return true;
    }

    bool Shutdown(GameMemory *mem) {
      uint64_t totalSize = RESERVED_SPACE_PERM + RESERVED_SPACE_TRANS;
      munmap(mem->permanentStorage, totalSize);
      return true;
    }

    GameMemory CreateState() {
      // TODO: Add checks for this failing
      uint64_t totalSize = RESERVED_SPACE_PERM + RESERVED_SPACE_TRANS;
      void* totalStorage = mmap(NULL, totalSize, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);

      if (totalStorage == MAP_FAILED) {
        errx(1, "mmap failed, exiting %i", errno);
      }

      GameMemory state =  {
                          RESERVED_SPACE_PERM,
                          totalStorage,
                          RESERVED_SPACE_TRANS,
                          ((uint8_t*)totalStorage + RESERVED_SPACE_PERM)
      };
      return state;
    }
  }
}
