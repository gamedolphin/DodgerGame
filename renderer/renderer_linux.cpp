#include "renderer.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
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

  // Set view 0 clear state.
  bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);

  bgfx::frame();

  return true;
}

bool Dodger::Renderer::Render(Dodger::Window::WindowConfig *windowConfig,
                              Dodger::Renderer::RenderObject *root) {

  bgfx::setViewRect(0, 0, 0, windowConfig->width, windowConfig->height);
  bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
  bgfx::touch(0);
  bgfx::frame();
  return true;
}

bool Dodger::Renderer::Shutdown (Dodger::Window::WindowConfig *windowConfig) {
  bgfx::shutdown();
  return true;
}
