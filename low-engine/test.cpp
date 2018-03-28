//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  test.cpp - 03/28/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Render/Display.h>

extern GLFWwindow* window;

int main() {

  lowengine::Display display;

  display.Initialize(lowengine::DisplayInfo(1024,768,"test"));

  if (display.IsInitialized() == false)
    return 1;

  do {

    glfwSwapBuffers(window);
    glfwPollEvents();

  }
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0);

  display.Terminate();

  return 0;
}