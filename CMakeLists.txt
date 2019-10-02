cmake_minimum_required(VERSION 3.10.2)
project(psr)

set(CMAKE_CXX_STANDARD 17)

# -O0 # add least optimization flag if needed for debugging
add_compile_options(-g -Wall -Wextra -Werror -pedantic)

add_subdirectory(src)
add_subdirectory(test)
