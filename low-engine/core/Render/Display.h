//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Display.h - 03/28/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_DISPLAY_
#define _LOWENGINE_DISPLAY_

#include <Common.h>

#include <string>

namespace lowengine
{

class DisplayInfo
{
public:
  GLsizei width;
  GLsizei height;
  std::string title;

  DisplayInfo(GLsizei width, GLsizei height, std::string&& title)
    : width(width), height(height), title(title) { }
};

class Display
{
  bool init = false;
public:

  void Initialize(DisplayInfo&& info);
  void Terminate();

  bool IsInitialized() const { return init; }
};

}
#endif