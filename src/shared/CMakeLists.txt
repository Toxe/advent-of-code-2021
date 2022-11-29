add_library(LIB_shared
        input_filename.cpp
        input_filename.hpp
        read_input.cpp
        read_input.hpp
)

set_target_properties(LIB_shared PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(LIB_shared PUBLIC cxx_std_20)
target_compile_options(LIB_shared PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(LIB_shared PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(LIB_shared PRIVATE ${SANITIZER_LINK_LIBRARIES})
target_include_directories(LIB_shared INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
