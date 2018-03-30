//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Render.h - 03/29/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_RENDER_
#define _LOWENGINE_RENDER_

#include <Common.h>

#include <Camera/Camera.h>
#include <Object/Object.h>
#include <vector>

namespace lowengine
{

class Render
{
  std::vector<Object *> objects;

public:

  void MainLoop();

  void AddObject(Object* obj) { objects.push_back(obj); }

};

}

#endif