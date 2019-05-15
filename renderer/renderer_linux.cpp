#include "renderer.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/math.h>
#include "../window/window.h"

#include "renderer_common.cpp"

void SetupPlatformData (Dodger::Window::WindowConfig *windowConfig, bgfx::PlatformData *pd) {
  auto wmi = Dodger::Window::GetPlatformInfo(windowConfig);

  pd->ndt = wmi.info.x11.display;
  pd->nwh = (void*)(uintptr_t)wmi.info.x11.window;
};



bool Dodger::Renderer::Initialize(Dodger::Window::WindowConfig *windowConfig) {

  bgfx::PlatformData pd;
  SetupPlatformData(windowConfig, &pd);

  bgfx::setPlatformData(pd);
  bgfx::renderFrame();

  bgfx::init();
  bgfx::reset(windowConfig->width, windowConfig->height, BGFX_RESET_VSYNC);

  // Enable debug text.
  bgfx::setDebug(BGFX_DEBUG_TEXT /*| BGFX_DEBUG_STATS*/);

  bgfx::setViewRect(0, 0, 0, windowConfig->width, windowConfig->height);

  // Set view 0 clear state.
  bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);

  bgfx::frame();

  Dodger::Renderer::InitializePrimitives();

  return true;
}

bool Dodger::Renderer::Render(Dodger::Window::WindowConfig *windowConfig,
                              Dodger::Renderer::RenderObject *root) {


  const bx::Vec3 at  = { 0.0f, 0.0f,   0.0f };
  const bx::Vec3 eye = { 0.0f, 0.0f, -35.0f };

  // Set view and projection matrix for view 0.
  {
    float view[16];
    bx::mtxLookAt(view, eye, at);

    float proj[16];
    bx::mtxProj(proj, 60.0f, float(windowConfig->width)/float(windowConfig->height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
    bgfx::setViewTransform(0, view, proj);

    // Set view 0 default viewport.
    bgfx::setViewRect(0, 0, 0, uint16_t(windowConfig->width), uint16_t(windowConfig->height) );
  }

  bgfx::touch(0);

  bgfx::IndexBufferHandle ibh = m_ibh;
  uint64_t state = 0
                | BGFX_STATE_WRITE_R
                | BGFX_STATE_WRITE_G
                | BGFX_STATE_WRITE_B
                | BGFX_STATE_WRITE_A
                | BGFX_STATE_WRITE_Z
                | BGFX_STATE_DEPTH_TEST_LESS
                | BGFX_STATE_CULL_CW
                | BGFX_STATE_MSAA
                | UINT64_C(0);

  Dodger::Renderer::RenderToFrame(root, state);

  bgfx::frame();
  return true;
}

bool Dodger::Renderer::Shutdown (Dodger::Window::WindowConfig *windowConfig) {
  bgfx::shutdown();
  return true;
}
