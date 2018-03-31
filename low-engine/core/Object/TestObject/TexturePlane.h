//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  TexturePlane.h - 03/31/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_TEXTUREPLANE_
#define _LOWENGINE_TEXTUREPLANE_

#include <Common.h>

#include <Object/Object.h>
#include <Shader/ShaderProgram.h>
#include <Texture/Texture.h>

#include <memory>

namespace lowengine
{

class TexturePlane : public Object
{
  ShaderProgram *program;
  Texture *texture;
  float width, height;

  GLuint matrix_id;
  GLuint texture_id;

public:

  TexturePlane(float width, float height);
  void RegisterTexture(std::unique_ptr<Texture>& texture);
  void RegisterShader(std::unique_ptr<ShaderProgram>& program);
  virtual void Draw();
};


}

#endif