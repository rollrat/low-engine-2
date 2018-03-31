//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  TexturePlane.cpp - 03/31/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Object/TestObject/TexturePlane.h>

#include <Camera/Camera.h>

extern lowengine::Camera camera;

lowengine::TexturePlane::TexturePlane(float width, float height)
  : width(width), height(height)
{
	const GLfloat g_vertex_buffer_data[] = { 
    -width, 0, -height,
    width, 0, -height,
    width, 0, height,
    -width, 0, height,
	};

	const GLfloat g_uv_buffer_data[] = { 
    0.0,0.0,
    1.0,0.0,
    1.0,1.0,
    0.0,1.0,
	};

  glGenBuffers(1, &vertex_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

  glGenBuffers(1, &uv_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

void lowengine::TexturePlane::RegisterTexture(std::unique_ptr<Texture>& texture)
{
  this->texture = texture.get();
}

void lowengine::TexturePlane::RegisterShader(std::unique_ptr<ShaderProgram>& program)
{
  this->program = program.get();

  matrix_id = glGetUniformLocation(program->GetId(), "MVP");
  texture_id = glGetUniformLocation(program->GetId(), "myTextureSampler");
}

void lowengine::TexturePlane::Draw()
{
  glm::mat4 ModelMatrix = glm::mat4(1.0);
  glm::mat4 MVP = camera.GetPV() * ModelMatrix;

  //program->Bind();

  //glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &MVP[0][0]);
  //glActiveTexture(GL_TEXTURE0);
  //texture->Bind();
  //glUniform1i(texture_id, 0);

  //// 1rst attribute buffer : vertices
  //glEnableVertexAttribArray(0);
  //glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  //glVertexAttribPointer(
  //  0,
  //  3,
  //  GL_FLOAT,
  //  GL_FALSE,
  //  0,
  //  (void*)0 
  //);

  //// 2nd attribute buffer : UVs
  //glEnableVertexAttribArray(1);
  //glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
  //glVertexAttribPointer(
  //  1,
  //  2,
  //  GL_FLOAT,
  //  GL_FALSE,
  //  0,
  //  (void*)0 
  //);

  //glDrawArrays(GL_TRIANGLES, 0, 6);

  //glDisableVertexAttribArray(0);
  //glDisableVertexAttribArray(1);

  //texture->UnBind();
  //program->UnBind();

  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf((GLfloat*)&camera.GetP());
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixf((GLfloat*)&camera.GetV());

  glLineWidth(2.0f);
  
  /*glBegin(GL_LINES);
  
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.1f, 0.0f); glVertex3f(1.1f, -0.1f, 0.0f);
    glVertex3f(1.1f, 0.1f, 0.0f); glVertex3f(1.0f, -0.1f, 0.0f);
    
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.05f, 1.25f, 0.0f); glVertex3f(0.0f, 1.15f, 0.0f);
    glVertex3f(0.05f, 1.25f, 0.0f); glVertex3f(0.0f, 1.15f, 0.0f);
    glVertex3f(0.0f, 1.15f, 0.0f); glVertex3f(0.0f, 1.05f, 0.0f);
    
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.05f, 0.1f, 1.05f); glVertex3f(0.05f, 0.1f, 1.05f);
    glVertex3f(0.05f, 0.1f, 1.05f); glVertex3f(-0.05f, -0.1f, 1.05f);
    glVertex3f(-0.05f, -0.1f, 1.05f); glVertex3f(0.05f, -0.1f, 1.05f);
    
  glEnd();*/
  
  glLineWidth(1.0f);
  
  glColor3f(1.0f, 1.0f, 1.0f);
  
  glBegin(GL_LINES);
  
  float d = 50.0f;
  
  for (float i = -d; i <= d; i += 1.0f)
  {
    glVertex3f(i, 0.0f, -d);
    glVertex3f(i, 0.0f, d);
    glVertex3f(-d, 0.0f, i);
    glVertex3f(d, 0.0f, i);
  }
  
  glEnd();
}
