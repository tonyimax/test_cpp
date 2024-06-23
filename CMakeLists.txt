cmake_minimum_required(VERSION 3.19) #cmake版本
project(test_cpp) #工程名
set(CMAKE_CXX_STANDARD 14) #使用C++标准14

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message("当前操作系统:macOS")
    set(SDL_DIR /usr/local/Cellar/sdl2/2.30.2/) #SDL目录
    include_directories(${SDL_DIR}/include/) #SDL头目录
    link_directories(${SDL_DIR}/lib/)        #SDL库目录
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("当前操作系统:Linux")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("当前操作系统:Windows")
endif ()


add_executable(test_cpp main.cpp)        #生成可执行文件
target_link_libraries(test_cpp SDL2 SDL2_test SDL2main) #链接SDL2 SDL2_test SDL2main这三个库
