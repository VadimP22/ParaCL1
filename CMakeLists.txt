cmake_minimum_required(VERSION 3.26.7)
project(paracl1 CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB PCL_SOURCES ${PROJECT_SOURCE_DIR}/Source/*.cpp)

set(PCL_TESTING_SOURCES ${PCL_SOURCES})
list(REMOVE_ITEM PCL_TESTING_SOURCES ${PROJECT_SOURCE_DIR}/Source/main.cpp)

add_library(pcllib OBJECT ${PCL_TESTING_SOURCES})
add_executable(pcl ${PCL_SOURCES})
target_include_directories(pcl PUBLIC ${PROJECT_SOURCE_DIR}/Include)

set_property(TARGET pcl PROPERTY CXX_STANDARD 20)
set_property(TARGET pcllib PROPERTY CXX_STANDARD 20)

file(GLOB TEST_SOURCES Test/*.cpp)

enable_testing()

foreach(TEST ${TEST_SOURCES})
    cmake_path(GET TEST FILENAME TEST_FILE_NAME)
    cmake_path(REMOVE_EXTENSION TEST_FILE_NAME)
    add_executable(${TEST_FILE_NAME} ${TEST})
    target_include_directories(${TEST_FILE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/Source)
    target_link_libraries(${TEST_FILE_NAME} pcllib)
    set_property(TARGET ${TEST_FILE_NAME} PROPERTY CXX_STANDARD 20)
    add_test(NAME ${TEST_FILE_NAME} COMMAND ${TEST_FILE_NAME})
endforeach()

add_custom_target(run
    COMMAND pcl
    DEPENDS pcl
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

# "Config" :)
target_compile_definitions(pcl PUBLIC DEBUG_MODE)
target_compile_definitions(pcllib PUBLIC DEBUG_MODE)

