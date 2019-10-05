file(GLOB psr_test_game_cpp
    "*.cpp"
    "Random/*.cpp"
    "Symbols/*.cpp")

set(parent_psr_test_game_cpp
    "${parent_psr_test_game_cpp}"
    "${psr_test_game_cpp}"
    PARENT_SCOPE)
