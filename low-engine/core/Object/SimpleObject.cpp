//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  SimpleObject.cpp - 03/31/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Object/SimpleObject.h>

#include <Camera/Camera.h>

extern lowengine::Camera camera;

void lowengine::SimpleObject::RegisterShader(std::unique_ptr<ShaderProgram>& program)
{
  this->program = program.get();

  // Must setting by shader value name.
  matrix_id = glGetUniformLocation(program->GetId(), "MVP");
  view_matrix_id = glGetUniformLocation(program->GetId(), "V");
  model_matrix_id = glGetUniformLocation(program->GetId(), "M");
}

void lowengine::SimpleObject::Draw()
{
  glm::mat4 ModelMatrix = glm::mat4(1.0);
  glm::mat4 MVP = camera.GetPV() * ModelMatrix;

  program->Bind();

  // Send our transformation to the currently bound shader, 
  // in the "MVP" uniform
  glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &MVP[0][0]);
  glUniformMatrix4fv(view_matrix_id, 1, GL_FALSE, &ModelMatrix[0][0]);
  glUniformMatrix4fv(model_matrix_id, 1, GL_FALSE, &camera.GetV()[0][0]);

  // Bind light
  // Bind texture

  // 1rst attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  glVertexAttribPointer(
    0,                  // attribute
    3,                  // size
    GL_FLOAT,           // type
    GL_FALSE,           // normalized?
    0,                  // stride
    (void*)0            // array buffer offset
  );

  // 2nd attribute buffer : UVs
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
  glVertexAttribPointer(
    1,                                // attribute
    2,                                // size
    GL_FLOAT,                         // type
    GL_FALSE,                         // normalized?
    0,                                // stride
    (void*)0                          // array buffer offset
  );

  // 3rd attribute buffer : normals
  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, normal_buffer);
  glVertexAttribPointer(
    2,                                // attribute
    3,                                // size
    GL_FLOAT,                         // type
    GL_FALSE,                         // normalized?
    0,                                // stride
    (void*)0                          // array buffer offset
  );

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);

  program->UnBind();
}
