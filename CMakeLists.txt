cmake_minimum_required(VERSION 2.8)
project(murpc)

set(CMAKE_BUILD_TYPE "Debug")
#set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
#add_compile_options(-fPIC)

add_subdirectory(src)
add_subdirectory(thirdparty)
add_subdirectory(test)
