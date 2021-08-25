cmake_minimum_required(VERSION 3.16)
project(C_Cpp_Test)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS -g)
set(CMAKE_CXX_FLAGS -g)

#add_definitions(-std=gnu++11)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../ThirdLib/googletest/googletest/include)
include_directories(${PROJECT_SOURCE_DIR}/../LeeCode/Include)
include_directories(${PROJECT_SOURCE_DIR}/../Practice/Include)

# 包含待测试文件
aux_source_directory(${PROJECT_SOURCE_DIR}/../LeeCode/Src/LeeCode TestSrc)
aux_source_directory(${PROJECT_SOURCE_DIR}/../LeeCode/Src/Algorithms TestSrc)
aux_source_directory(${PROJECT_SOURCE_DIR}/../Practice/Src TestSrc)

# 包含测试文件
aux_source_directory(. TestSrc)
aux_source_directory(LeeCode TestSrc)
aux_source_directory(LeeCode/Algorithms TestSrc)
aux_source_directory(Practice TestSrc)
aux_source_directory(Utils TestSrc)

add_subdirectory(${PROJECT_SOURCE_DIR}/../ThirdLib/googletest googletest_dir)

link_directories(${PROJECT_SOURCE_DIR}/../ThirdLib/googletest/googletest/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Bin)
message(STATUS "Bin path: ${EXECUTABLE_OUTPUT_PATH}")

add_executable(gtester ${TestSrc})
target_link_libraries(gtester gtest)