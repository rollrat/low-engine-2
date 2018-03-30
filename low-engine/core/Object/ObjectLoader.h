//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  ObjectLoader.h - 03/30/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_OBJECTLOADER_
#define _LOWENGINE_OBJECTLOADER_

#include <Object/Object.h>

namespace lowengine
{

class ObjectLoader
{
public:

  static Object CreateProject(std::string&& path);

};


}


#endif