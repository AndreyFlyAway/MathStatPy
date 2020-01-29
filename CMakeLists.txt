cmake_minimum_required(VERSION 2.8)

project (MathStatPyLib)

set(NAME MathStatPyLib)

set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_FLAGS "-fpermissive")

set(I /usr/local/include/python3.8/)
	
include_directories(src)

add_library(MathStatPyLib SHARED
		src/combinatorics.cpp
		src/combinatorics.h
		src/probability_type.cpp
		src/probability_type.h
			MathStatPy.c)

include_directories(/usr/local/include/python3.8/)

target_link_libraries(MathStatPyLib ${PYTHON_LIBRARIES})
#target_link_libraries(MathStatPyLib c:/Python38-32/libs/python38.lib)

