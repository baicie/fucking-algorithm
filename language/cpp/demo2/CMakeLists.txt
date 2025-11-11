cmake_minimum_required(VERSION 3.10)

# 项目名称
project(WorkerManagerProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加源文件
set(SOURCES
    main.cpp
    workerManager.cpp
)

# 可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 生成可执行文件
add_executable(WorkerManagerApp ${SOURCES})

# 添加编译选项
target_compile_options(WorkerManagerApp PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align
    -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0
)
