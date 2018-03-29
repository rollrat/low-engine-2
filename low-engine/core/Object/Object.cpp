//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Object.cpp - 03/29/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Object/Object.h>

glm::mat4 lowengine::Object::GetM()
{
  glm::mat4 matrix;

  matrix = glm::translate(matrix, position);

  matrix = glm::rotate(matrix, glm::radians(rotation.x), { 1, 0, 0 });
  matrix = glm::rotate(matrix, glm::radians(rotation.y), { 0, 1, 0 });
  matrix = glm::rotate(matrix, glm::radians(rotation.z), { 0, 0, 1 });

  return matrix;
}
