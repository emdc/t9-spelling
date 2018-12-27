cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(t9-spelling
	LANGUAGES CXX
	VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR}/${CMAKE_BUILD_TYPE})

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/catch)

set(APP_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/t9spelling.hpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/catch/single_include)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_executable(t9-spelling
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${APP_SOURCES}
)
add_executable(t9-spelling-test
	${CMAKE_CURRENT_SOURCE_DIR}/test/main.test.cpp
	${APP_SOURCES}
)
target_link_libraries(t9-spelling-test Catch)
