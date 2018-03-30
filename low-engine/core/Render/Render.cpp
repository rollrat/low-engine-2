//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Render.cpp - 03/29/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Render/Render.h>

#include <Shader/ShaderLoader.h>

extern GLFWwindow* window;

lowengine::Camera camera;

void lowengine::Render::MainLoop()
{
  do {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.Update();
    for (auto& obj : objects)
      obj->Draw();

    glfwSwapBuffers(window);
    glfwPollEvents();

  } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0);
}
