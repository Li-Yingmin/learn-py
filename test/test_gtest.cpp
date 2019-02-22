/*!
 * -------------------------------------------
 * Copyright (c) 2019, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     test_gtest.cpp
 * \Author   Yingmin Li
 * \Mail     yingmin.li@horizon.ai
 * \Version  1.0.0.0
 * \Date     2019-02-22
 * \Brief    implement of test_gtest.cpp
 * \DO NOT MODIFY THIS COMMENT, \
 * \WHICH IS AUTO GENERATED BY EDITOR
 * -------------------------------------------
 */
#include "gtest/gtest.h"
#include "hobotlog/hobotlog.hpp"
#include "learn_py/learn_py.h"
#include <sys/utsname.h>

namespace {

TEST(test, gtest) {
  SetLogLevel(INFO);
  example::HelloWorldlearn_py obj;
  int a = 0;
  int b = 34;
  struct utsname name;
  if (uname(&name)) {
    exit(-1);
  }
  LOGI << "Hello! Your remote computer's OS is "
       << name.sysname << " "
       << name.release;
  LOGI << "Test learn_py gtest success";
}

}
