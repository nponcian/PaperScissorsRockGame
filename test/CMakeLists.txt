# Keep this up to date with setup process in https://github.com/google/googletest
# More information in googletest/googletest README file

cmake_minimum_required(VERSION 3.10.2)
project(psr_test)

# googletest setup code start

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
# if (CMAKE_VERSION VERSION_LESS 2.8.11)
#   include_directories("${gtest_SOURCE_DIR}/include")
# endif()

# googletest setup code end

include_directories("${gmock_SOURCE_DIR}/include")
include_directories("${gtest_SOURCE_DIR}/include")
include_directories(../src)
include_directories(.)

# Define macro flag DONT_PRINT_TO_SCREEN to compilation of all executables after this command, including
# those in the subdirectories added after this. This is added specifically for everything under the
# test folder to restrict the prints made by the src codes that are being tested. Search the src code
# for more info about handling this macro flag DONT_PRINT_TO_SCREEN.
add_definitions(-DDONT_PRINT_TO_SCREEN)

# Declare the variables that needs to be passed to the subdirectories. The idea is to get all cpp
# files from all subdirectories and compile them all here into a single test executable.
set(parent_psr_test_game_cpp "")

# Add the subdirectories. Each subdirectory should modify their respective parent_psr_test_*_cpp
# variable with all their cpp files for compilation here.
add_subdirectory(Game)

# Add the test cpp files from this directory
file(GLOB psr_test_cpp
    "*.cpp")

# Create the executable with all the cpp files from the whole test directory and subdirectories
add_executable(
    psr_test
    ${psr_test_cpp}
    ${parent_psr_test_game_cpp})

# Link against required libraries
target_link_libraries(psr_test gmock_main)
target_link_libraries(psr_test gtest_main)
target_link_libraries(psr_test psr_src_game_FOR_TESTING)
# target_link_libraries(psr_test psr_src_common_FOR_TESTING)

add_test(NAME psr_test COMMAND psr_test)
