cmake_minimum_required(VERSION 2.8)

project (MathStatPyLib)

set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_FLAGS "-fpermissive")
set(I /usr/local/include/python3.8/)

add_library(MathStatPyLib SHARED
	    common/combinatorics.c
            common/combinatorics.h
            MathStatPy.c)

            
include_directories(common)
include_directories(/usr/local/include/python3.8/)

target_link_libraries(MathStatPyLib ${PYTHON_LIBRARIES})

