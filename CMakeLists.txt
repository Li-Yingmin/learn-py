cmake_minimum_required(VERSION 2.8)

# 将hobot_util.cmake添加到该cmakelists
include(cmake/hobot_util.cmake)

# 项目名称
project(learn_py)

# 一些平台相关的设置
if (APPLE)
  set(CMAKE_MACOSX_RPATH ON)
endif ()

if (${PLATFORM_MAC})
    add_definitions(-DHR_POSIX)
    add_definitions(-DHR_MAC)
elseif (${PLATFORM_LINUX})
    add_definitions(-DHR_POSIX)
    add_definitions(-DHR_LINUX)
elseif (${PLATFORM_ANDROID})
    set(ENABLE_NEON "true")
    add_definitions(-DENABLE_OMP)
    add_definitions(-DHR_POSIX)
    add_definitions(-DHR_ANDROID)
elseif (${PLATFORM_WIN})
    set(CMAKE_CXX_FLAGS_RELEASE "/MD")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
    add_definitions(-DHR_WIN)
    add_definitions(-D_MBCS)
    add_definitions(-DHOBOT_EXPORTS)
else ()
    message(FATAL_ERROR "invoke cmake with -DPLATFORM_MAC=TRUE|-DPLATFORM_LINUX=TRUE|-DPLATFORM_ANDROID=TRUE|-DPLATFORM_WIN=TRUE")
    return()
endif ()
# 编译模式
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

# 编译参数
if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -fPIC -fopenmp -Ofast ")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -DEBUG -g -O0 -fPIC -fopenmp")
endif ()

# 添加头文件路径，所有头文件和源文件的inlcude都可以直接include faiss_dbscan/faiss_dbscan.h
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)
# 头文件路径信息
file(GLOB PROJECT_INC
        "include/*.h"
        "include/*.hpp"
        "include/learn_py/*.h"
        "include/learn_py/utils/*.h"
        )

# 源文件路径信息
file(GLOB PROJECT_SRC
        "src/learn_py/*.cpp"
        "src/utils/*.cpp"
        )
# 表示所有.h和.cpp文件的变量SOURCE_FILES
set(SOURCE_FILES
        ${PROJECT_SRC}
        ${PROJECT_INC}
        )
# 添加目标共享库libtestdemo.so，默认在build中生成，但是hobot_util.cmake已经设置了在build/lib生成.so
# 编译.so的时候不需要target_link_libraries
# 生成可执行的时候才需要target_link_libraries
add_library(learn_py SHARED ${SOURCE_FILES})

# add subdir swig
# add_subdirectory(src swig)


add_subdirectory(test)

# make install才会安装
set(OUTPUT_ROOT ${PROJECT_SOURCE_DIR}/output)
set(MY_OUTPUT_ROOT ${OUTPUT_ROOT}/learn_py)

install(TARGETS learn_py
    DESTINATION ${MY_OUTPUT_ROOT}/lib)
install(FILES ${PROJECT_INC}
    DESTINATION ${MY_OUTPUT_ROOT}/include/learn_py/)

# set python path
# message("-- install related file to python env...")
# message("PYTHON_OUTPUT_PACKAGE_DIR = ${PYTHON_OUTPUT_PACKAGE_DIR}")
# set(LIB_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib" )
# set(PYTHON_INC_PATH "${PROJECT_BINARY_DIR}/swig")
# install(FILES  ${LIB_OUTPUT_PATH}/_learn_py.so ${PYTHON_INC_PATH}/learn_py.py
#        DESTINATION ${PYTHON_OUTPUT_PACKAGE_DIR}/)
