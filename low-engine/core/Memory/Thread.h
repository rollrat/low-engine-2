//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Thread.h - 03/30/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_THREAD_
#define _LOWENGINE_THREAD_

#include <Common.h>

#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>

namespace lowengine
{

class Semaphore
{
  std::mutex mtx;
  std::condition_variable cv;
  size_t count = 0;

public:

  inline void notify()
  {
    std::unique_lock<decltype(mtx)> lock(mtx);
    count++;
    cv.notify_one();
  }

  inline void wait()
  {
    std::unique_lock<decltype(mtx)> lock(mtx);
    while (!count)
      cv.wait(lock);
    count--;
  }

  bool try_wait()
  {
    std::unique_lock<decltype(mtx)> lock(mtx);
    if (count) {
      count--; // will be increased in notify().
      return true;
    }
    return false;
  }

};

class Thread
{
public:


};


}

#endif