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

extern GLFWwindow* window;

lowengine::Camera camera;

void lowengine::Render::MainLoop()
{
  do {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.Update();
    glm::mat4 ModelMatrix = glm::mat4(1.0);
    glm::mat4 MVP = camera.GetPV() * ModelMatrix;
    //glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glfwSwapBuffers(window);
    glfwPollEvents();

  } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0);
}
