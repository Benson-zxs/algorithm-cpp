# CMakeList.txt: Algorithms 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# 将源代码添加到此项目的可执行文件。
add_executable (Algorithms "Algorithms.cpp" "Algorithms.h")
add_executable(code04-1 "Section-1/Chapter4/Part1.cpp")
add_executable(code06-test-heap-sort "Section-2/Chapter6/test_heap_sort.cpp" Section-2/Chapter6/)

# TODO: 如有需要，请添加测试并安装目标。
