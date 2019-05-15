#include "renderer.h"
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include "renderer_primitives.cpp"

namespace Dodger {
  namespace Renderer {
    RenderObject CreateRoot() {
      Renderer::RenderObject obj;
      obj.id = 0;
      obj.type = Renderer::NONE;
      obj.parent = nullptr;
      return obj;
    };

    void RenderToFrame (Renderer::RenderObject *data, uint64_t state) {

      // Set model matrix for rendering.

      bgfx::setTransform(data->mtx);
      // Set vertex and index buffer.
      bgfx::setVertexBuffer(0, m_vbh);
      bgfx::setIndexBuffer(m_ibh);

      bgfx::setState(state);

      // bgfx::submit(0, m_program);
    }
  }
}
