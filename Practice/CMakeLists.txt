cmake_minimum_required(VERSION 3.16)
project(C_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(practice
        main.cpp
        my_smart_ptr.cpp my_non_member.cpp ../Test/main.cpp ../Test/LeeCode/AlgorithmsTest.cpp ../Test/LeeCode/LeeCodeTest.cpp ../Test/Practice/PracticeTest.cpp)