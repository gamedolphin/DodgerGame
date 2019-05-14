#ifndef HEADER_RENDERER
#define HEADER_RENDERER
#include <vector>
#include "../window/window.h"

namespace Dodger {
  namespace Renderer {

    enum RenderType {
                     NONE
    };

    struct RenderObject {
      uint8_t id;
      RenderType type;
      RenderObject* parent;
      std::vector<RenderObject*> children;
    };

    bool Initialize(Dodger::Window::WindowConfig *window);
    bool Render(Dodger::Window::WindowConfig *window, RenderObject* root);
    bool Shutdown(Dodger::Window::WindowConfig *window);
    RenderObject CreateRoot();
  }
}

#endif
