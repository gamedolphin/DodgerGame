#include "renderer.h"

Dodger::Renderer::RenderObject Dodger::Renderer::CreateRoot() {
  Dodger::Renderer::RenderObject obj;
  obj.id = 0;
  obj.type = Dodger::Renderer::NONE;
  obj.parent = nullptr;
  return obj;
};
