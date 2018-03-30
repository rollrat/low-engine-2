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
protected:

  GLuint vertex_buffer;
  GLuint uv_buffer;

  glm::vec3 position;
  glm::vec3 rotation;

public:

  Object() { }
  Object(GLuint vertex_buffer, GLuint uv_buffer)
    : vertex_buffer(vertex_buffer), uv_buffer(uv_buffer) { }

  glm::mat4 GetM();

  virtual void Draw();

  glm::vec3& Position() { return position; }
  glm::vec3& Rotation() { return rotation; }
};


}


#endif