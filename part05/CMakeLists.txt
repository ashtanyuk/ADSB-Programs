set(part05_files simpleSort.h advanceSort.h)
set(header_05_1 ${CMAKE_CURRENT_SOURCE_DIR}/simpleSort.h)
set(header_05_2 ${CMAKE_CURRENT_SOURCE_DIR}/advanceSort.h)

#add_library(lib_05 STATIC ${part05_files})
#target_link_libraries(lib_05 pthread)

#target_include_directories(lib_05 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(lib_05 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
install(FILES ${header_05_1} DESTINATION "${include_dest}")
#install(FILES ${header_05_2} DESTINATION "${include_dest}")