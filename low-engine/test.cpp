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
#include <Object/TestObject/TexturePlane.h>

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

  //glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  glEnable(GL_DEPTH_TEST);
  //glDepthFunc(GL_LESS);

  glEnable(GL_CULL_FACE);

  /////////////////////////////////////////////////////////////////////////

  lowengine::Render render;
  lowengine::ShaderProgram shader1("TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader");
  render.AddObject(new lowengine::ShaderSolidCube( shader1 ));

  std::unique_ptr<lowengine::ShaderProgram> shader2 = std::make_unique<lowengine::ShaderProgram>("TransformVertexShader2.vertexshader", "TextureFragmentShader.fragmentshader");
  std::unique_ptr<lowengine::Texture> texture = std::make_unique<lowengine::Texture>();
  texture->LoadTexture("tile-texture.jpg");
  lowengine::TexturePlane *tex_plane = new lowengine::TexturePlane(100.0, 100.0);
  tex_plane->RegisterShader(shader2);
  tex_plane->RegisterTexture(texture);
  render.AddObject(tex_plane);

  render.MainLoop();
  display.Terminate();

  return 0;
}