cmake_minimum_required(VERSION 3.17)
project(cplusplus_puzzles)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -g")

<<<<<<< Updated upstream
add_executable(cplusplus_puzzles codechef/compete/2021/LTIME102/SUBJUMP.cpp)

=======
add_executable(cplusplus_puzzles codechef/compete/2022/LTIME104B/PERMXORSUM.cpp)
>>>>>>> Stashed changes
