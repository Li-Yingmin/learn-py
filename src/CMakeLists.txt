# use SWIG
include(../cmake/FindPythonAnaconda.cmake)

# find python related path
# find_package(PythonLibs)
# set(PYTHON_LIBRARIES /home/users/rui.shi/anaconda2/lib/libpython2.7.so)
# set(PYTHON_INCLUDE_PATH /home/users/rui.shi/anaconda2/include/python2.7)
# set(PYTHON_INCLUDE_DIRS /home/users/rui.shi/anaconda2/include/python2.7)
include_directories(${PYTHON_INCLUDE_DIRS})
#message(STATUS "PYTHON_LIBRARIES = " ${PYTHON_LIBRARIES})
#message(STATUS "PYTHON_INCLUDE_PATH = " ${PYTHON_INCLUDE_PATH})
#message(STATUS "PYTHON_INCLUDE_DIRS = " ${PYTHON_INCLUDE_DIRS})
#message(STATUS "PYTHON_DEBUG_LIBRARIES = " ${PYTHON_DEBUG_LIBRARIES})
#message(STATUS "PYTHONLIBS_VERSION_STRING = " ${PYTHONLIBS_VERSION_STRING})

# find swig related path
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
# Set the properties for the interface file.
set(IDL_PATH_FILE myswig.i)
set(WARP_PATH_FILE learn_py/learn_py.cpp)

set_source_files_properties(${IDL_PATH_FILE} PROPERTIES CPLUSPLUS ON)

swig_add_module(learn_py python ${IDL_PATH_FILE} ${WARP_PATH_FILE})
swig_link_libraries(learn_py ${PYTHON_LIBRARIES} learn_py faiss hobotlog)