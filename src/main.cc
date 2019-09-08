#include "game/Entity.hh"
#include "render/Window.hh"

using namespace game;

int main() {
  Entity entity = Entity();

  for (int i = 0; i < 60 * 70; ++i) {
    entity.update();
  }

  render::Window window;
//  window.init();
//  glfwTerminate();
//  render::Window window;
//  game::Engine engine;
  return 0;
}
