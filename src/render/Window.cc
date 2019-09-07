#include <iostream>
#include "Window.hh"

namespace render {
  Window::Window() {
  }

  int Window::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
    }

    glViewport(0, 0, 800, 600);

    while (!glfwWindowShouldClose(window)) {
      processInput(window);

      glfwSwapBuffers(window);
      glfwPollEvents();
    }
    return 0;
  }

  void Window::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);
  }
}
