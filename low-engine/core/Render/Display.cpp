//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Display.cpp - 03/28/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Render/Display.h>

#include <stdio.h>
#include <stdlib.h>

GLFWwindow* window;
lowengine::DisplayInfo* display_info;

void lowengine::Display::Initialize(DisplayInfo&& info)
{
  if (!glfwInit())
  {
    fprintf(stderr, "GLFW 초기화 실패\n");
    return;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(info.width, info.height, info.title.c_str(), NULL, NULL);

  glfwMakeContextCurrent(window);
  glewExperimental = true;
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "GLEW 초기화 실패\n");
    return;
  }

  /* optional */ glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  display_info = new lowengine::DisplayInfo(info);

  this->init = true;
}

void lowengine::Display::Terminate()
{
  glfwTerminate();
}
