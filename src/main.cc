#include "game/Engine.hh"
#include "render/Window.hh"
#include "reactphysics3d.h"

using namespace render;

int main() {
  auto *sphereShape = new reactphysics3d::SphereShape(3);
  Window window;
  window.init();
  glfwTerminate();
//  render::Window window;
//  game::Engine engine;
  return 0;
}
