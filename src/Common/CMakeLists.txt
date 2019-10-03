file(GLOB psr_src_common_cpp
    "*.cpp")

add_library(psr_src_common ${psr_src_common_cpp})

add_library(psr_src_common_FOR_TESTING ${psr_src_common_cpp})
target_compile_definitions(psr_src_common_FOR_TESTING PUBLIC DONT_PRINT_TO_SCREEN)
