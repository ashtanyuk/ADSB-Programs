set(part03_files part03.h strSearch.cpp)
set(header_03 ${CMAKE_CURRENT_SOURCE_DIR}/part03.h)

add_library(lib_03 STATIC ${part03_files})
target_link_libraries(lib_03 pthread)

target_include_directories(lib_03 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(FILES ${header_03} DESTINATION "${include_dest}")