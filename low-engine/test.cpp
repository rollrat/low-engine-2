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
#include <Render/Render.h>

#include <Object/TestObject/ShaderSolidCube.h>

extern GLFWwindow* window;

int main() {

  lowengine::Display display;

  display.Initialize(lowengine::DisplayInfo(1024,768,"test"));

  if (display.IsInitialized() == false)
    return 1;

  /////////////////////////////////////////////////////////////////////////

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  glfwPollEvents();
  glfwSetCursorPos(window, 1024 / 2, 768 / 2);

  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glEnable(GL_CULL_FACE);

  /////////////////////////////////////////////////////////////////////////

  lowengine::Render render;
  lowengine::ShaderProgram shader1("TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader");
  render.AddObject(new lowengine::ShaderSolidCube( shader1 ));

  render.MainLoop();

  display.Terminate();

  return 0;
}