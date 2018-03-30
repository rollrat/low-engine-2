//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  ShaderSolidCube.h - 03/30/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_SHADERSOLIDCUBE_
#define _LOWENGINE_SHADERSOLIDCUBE_

#include <Common.h>

#include <Object/Object.h>
#include <Shader/ShaderProgram.h>

namespace lowengine
{

class ShaderSolidCube : public Object
{
  ShaderProgram& program;
  GLuint matrix_id;

public:

  ShaderSolidCube(ShaderProgram& program);

  virtual void Draw();

};


}

#endif