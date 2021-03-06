//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  ShaderLoader.h - 03/28/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_SHADERLOADER_
#define _LOWENGINE_SHADERLOADER_

#include <Common.h>

#include <string>

namespace lowengine
{

class ShaderLoader
{
  static std::string ReadShader(const char *filename);
  static GLuint CreateShader(GLenum shaderType, std::string source, const char* shaderName);

public:

  static GLuint CreateProgram(const char* VertexShaderFilename, const char* FragmentShaderFilename);
};

}


#endif