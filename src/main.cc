#include "game/Engine.hh"
#include "render/Window.hh"

using namespace render;

int main() {
  Window window;
  window.init();
  glfwTerminate();
//  render::Window window;
//  game::Engine engine;
  return 0;
}
