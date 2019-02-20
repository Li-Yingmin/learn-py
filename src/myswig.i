%module learn_py
%{
#include "learn_py/learn_py.h"
%}
%include "carrays.i"
%array_class(float, floatArray);
%array_class(long, intArray);
%array_class(unsigned char, ucharArray);
%include "learn_py/learn_py.h"

