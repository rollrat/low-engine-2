//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  ShaderProgram.cpp - 03/29/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Shader/ShaderProgram.h>

#include <Shader/ShaderLoader.h>

lowengine::ShaderProgram::ShaderProgram(std::string && VertexShaderFilename, std::string && FragmentShaderFilename)
{
  id = lowengine::ShaderLoader::CreateProgram(VertexShaderFilename.c_str(), FragmentShaderFilename.c_str());
}

lowengine::ShaderProgram::~ShaderProgram()
{
  glDeleteProgram(id);
}

void lowengine::ShaderProgram::Bind()
{
  glUseProgram(id);
}

void lowengine::ShaderProgram::UnBind()
{
  glUseProgram(0);
}
