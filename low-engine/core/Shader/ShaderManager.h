//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  ShaderManager.h - 03/30/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_SHADERMANAGER_
#define _LOWENGINE_SHADERMANAGER_

#include <Common.h>

#include <Shader/ShaderProgram.h>
#include <Shader/ShaderLoader.h>

#include <map>
#include <memory>

namespace lowengine
{

class ShaderManager
{
  std::map<std::string, 
    std::unique_ptr<ShaderProgram>> shader_programs;

public:

};

}


#endif