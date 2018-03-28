//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Texture.h - 03/28/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Texture/Texture.h>

#include <SFML/Graphics/Image.hpp>

bool lowengine::Texture::LoadTexture(std::string path)
{
  sf::Image image;

  if (!image.loadFromFile(path))
  {
    return false;
  }

  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);

  glTexImage2D(
    GL_TEXTURE_2D, 0, GL_RGBA,
    image.getSize().x, image.getSize().y, 0,
    GL_RGBA, GL_UNSIGNED_BYTE,
    image.getPixelsPtr()
  );

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glGenerateMipmap(GL_TEXTURE_2D);

  return true;
}
