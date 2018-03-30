//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  SimpleObject.h - 03/31/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_SIMPLEOBJECT_
#define _LOWENGINE_SIMPLEOBJECT_

#include <Object/Object.h>
#include <Shader/ShaderProgram.h>

#include <memory>

namespace lowengine
{

class SimpleObject : public Object
{
  ShaderProgram *program;

  GLuint matrix_id;
  GLuint view_matrix_id;
  GLuint model_matrix_id;

public:

  SimpleObject() { }
  SimpleObject(GLuint vertex_buffer, GLuint uv_buffer, GLuint normal_buffer)
    : Object(vertex_buffer, uv_buffer, normal_buffer) { }

  void RegisterShader(std::unique_ptr<ShaderProgram>& program);
  virtual void Draw();

};


}


#endif