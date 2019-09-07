#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace render {
  class Window {
  public:
    int init();

    void processInput(GLFWwindow *window);
  };
}
