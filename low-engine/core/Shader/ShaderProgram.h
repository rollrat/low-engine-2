//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  ShaderProgram.h - 03/29/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_SHADERPROGRAM_
#define _LOWENGINE_SHADERPROGRAM_

#include <Common.h>

#include <string>

namespace lowengine
{

class ShaderProgram
{
  GLuint id;
public:

  ShaderProgram(std::string&& VertexShaderFilename, std::string&& FragmentShaderFilename);
  ~ShaderProgram();

  void Bind();
  void UnBind();

};

}


#endif