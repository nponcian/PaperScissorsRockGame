cmake_minimum_required(VERSION 3.10.2)
project(psr_src)

# Include current src/ directory. This implies that if a header file is to be included in one of the
# files in the subdirectories, it should be done with respect to src/ directory. Take note that including
# relative paths are discouraged.
include_directories(.)

# Add the subdirectories
# add_subdirectory(Common)
add_subdirectory(Help)
add_subdirectory(Game)

# Add the src cpp files from this directory
file(GLOB psr_src_cpp
    "*.cpp")

# Create the executable with the cpp files here in src directory
add_executable(psr_src ${psr_src_cpp})

# Link against required libraries
target_link_libraries(psr_src psr_src_help)
target_link_libraries(psr_src psr_src_game)
# target_link_libraries(psr_src psr_src_common)
