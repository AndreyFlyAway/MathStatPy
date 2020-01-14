cmake_minimum_required(VERSION 2.8)

project (MathStatPyLib)

set(NAME MathStatPyLib)

set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_FLAGS "-fpermissive")


if (WIN32)
	set(I c:/Python38-32/include/)
	include_directories(I c:/Python38-32/include/)
	message("O-o-ops!")
elseif(LINUX) 
	set(I /usr/local/include/python3.8/)
	include_directories(/usr/local/include/python3.8/)
endif(WIN32)
	
include_directories(common)

add_library(MathStatPyLib SHARED
			common/combinatorics.cpp
            common/combinatorics.h
			MathStatPy.c)
			
target_link_libraries(MathStatPyLib ${PYTHON_LIBRARIES})
#target_link_libraries(MathStatPyLib c:/Python38-32/libs/python38.lib)

