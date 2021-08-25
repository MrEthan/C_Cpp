cmake_minimum_required(VERSION 3.16)
project(Practice)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS -g)
set(CMAKE_CXX_FLAGS -g)

include_directories(Include)

aux_source_directory(. ExecuteSrc)
aux_source_directory(Src PracticeSrc)

set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/Lib)
message(STATUS "Lib path: ${LIBRARY_OUTPUT_PATH}")
# 生成静态库
add_library(PracticeStatic STATIC ${PracticeSrc})
# add_library(Practice SHARED ${PracticeSrc})

# 生成可执行文件
link_directories(${PROJECT_SOURCE_DIR}/Lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Bin)
message(STATUS "Bin path: ${EXECUTABLE_OUTPUT_PATH}")

add_executable(practice.out ${PracticeSrc} ${ExecuteSrc})
target_link_libraries(practice.out PracticeStatic)