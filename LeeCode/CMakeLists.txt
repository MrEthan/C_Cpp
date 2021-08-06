cmake_minimum_required(VERSION 3.16)
project(C_Cpp_LeeCode)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS -g)
set(CMAKE_CXX_FLAGS -g)

include_directories(Include)

aux_source_directory(Src/LeeCode LeeCodeSrc)
aux_source_directory(Src/Algorithms LeeCodeSrc)

set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/Lib)
message(STATUS "Lib path: ${LIBRARY_OUTPUT_PATH}")
# 生成静态库
add_library(LeeCodeStatic STATIC ${LeeCodeSrc})
# add_library(LeeCode SHARED ${LeeCodeSrc})