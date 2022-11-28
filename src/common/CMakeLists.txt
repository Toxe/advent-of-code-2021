add_library(common
        input_filename.cpp
        input_filename.hpp
        read_input.cpp
        read_input.hpp
)

set_target_properties(common PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(common PUBLIC cxx_std_20)
target_compile_options(common PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(common PRIVATE ${SANITIZER_FLAGS})
target_include_directories(common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
