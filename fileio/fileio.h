#ifndef HEADER_FILEIO
#define HEADER_FILEIO
#include <cstdint>

namespace Dodger {
  namespace FileIO {

    bool Initialize();
    void ReadFile(const char* filename, uint8_t* data);
    bool Shutdown();
  }
}

#endif
