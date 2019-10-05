file(GLOB psr_src_game_cpp
    "*.cpp"
    "Level/*.cpp"
    "Output/*.cpp"
    "Random/*.cpp"
    "Symbols/*.cpp")

add_library(psr_src_game ${psr_src_game_cpp})

# The next command recompiles the src codes but now with the additional defined macro flag DONT_PRINT_TO_SCREEN.
# This library should be the one linked to the tests! Why? Because linking tests against the library
# without this defined macro flag would result to printing everything that the src code processes into
# the screen while being invoked by the tests which is not necessary when testing. Search the src code
# for more info about handling this macro flag DONT_PRINT_TO_SCREEN.
add_library(psr_src_game_FOR_TESTING ${psr_src_game_cpp})
target_compile_definitions(psr_src_game_FOR_TESTING PUBLIC DONT_PRINT_TO_SCREEN)
