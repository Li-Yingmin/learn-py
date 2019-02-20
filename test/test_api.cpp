/*!
 * Copyright (c) 2016-present, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     test_api.cpp
 * \Author   Yingmin Li
 * \Mail     yingmin.li-horizon.ai
 * \Version  1.0.0.0
 * \Date     2019/1/10
 * \Brief    implement of test_api.cpp
 */
#include "gtest/gtest.h"
#include "hobotlog/hobotlog.hpp"
#include "learn_py/learn_py.h"

namespace {

TEST(learn_py, api) {
  SetLogLevel(INFO);
  LOGI << "Test learn_py api file success";
}

}