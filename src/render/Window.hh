#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace render {
  class Window {
  public:
    Window();

    int init();

    void processInput(GLFWwindow *window);
  };
}

