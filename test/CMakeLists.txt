add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests03.cpp
  tests05.cpp
  tests06.cpp
  tests07.cpp
  tests08.cpp
)
		
target_include_directories(${PROJECT_NAME}.test PUBLIC ${PROJECT_SOURCE_DIR}/part03)
target_include_directories(${PROJECT_NAME}.test PUBLIC ${PROJECT_SOURCE_DIR}/part05)
target_include_directories(${PROJECT_NAME}.test PUBLIC ${PROJECT_SOURCE_DIR}/part06)
target_include_directories(${PROJECT_NAME}.test PUBLIC ${PROJECT_SOURCE_DIR}/part07)
target_include_directories(${PROJECT_NAME}.test PUBLIC ${PROJECT_SOURCE_DIR}/part08)

target_link_libraries(${PROJECT_NAME}.test lib_03 gtest pthread)

target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")
