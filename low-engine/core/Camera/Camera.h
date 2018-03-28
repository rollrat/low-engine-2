//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Camera.h - 03/21/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_CAMERA_
#define _LOWENGINE_CAMERA_

#include <Common.h>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace lowengine
{

class Camera
{
public:

  Camera();

  std::string to_string();

  glm::vec3& GetPosition();

  GLfloat GetHorizontalAngle() const;
  void SetHorizontalAngle(GLfloat angle);

  GLfloat GetVerticalAngle() const;
  void SetVerticalAngle(GLfloat angle);

  void Update();
  glm::mat4 GetPV();
};

}

#endif