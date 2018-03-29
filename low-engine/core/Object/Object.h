//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Object.h - 03/29/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_OBJECT_
#define _LOWENGINE_OBJECT_

#include <Common.h>

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace lowengine
{

class Object
{
  GLuint vertex_buffer;
  GLuint uv_buffer;

  glm::vec3 position;
  glm::vec3 rotation;

public:

  glm::mat4 GetM();

  // 순수 가상함수 아님
  virtual void Draw();

};


}


#endif