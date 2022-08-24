cmake_minimum_required (VERSION 3.10)
project (ADSB-Programs)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")

set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(part03)
add_subdirectory(part05)
add_subdirectory(part06)
add_subdirectory(part07)
add_subdirectory(part08)
add_subdirectory(test)
