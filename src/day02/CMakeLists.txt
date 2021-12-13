add_executable(day02 main.cpp day02.cpp day02.hpp)

set_target_properties(day02 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day02 PUBLIC cxx_std_20)
target_compile_options(day02 PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_options(day02 PRIVATE ${SANITIZER_FLAGS})
target_link_libraries(day02 PRIVATE common)

# Tests
if(BUILD_TESTING)
    add_executable(day02_tests tests.cpp day02.cpp day02.hpp)

    set_target_properties(day02_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(day02_tests PUBLIC cxx_std_20)
    target_compile_options(day02_tests PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_link_options(day02_tests PRIVATE ${SANITIZER_FLAGS})
    target_link_libraries(day02_tests PRIVATE Catch2::Catch2WithMain)

    add_test(NAME day02_tests COMMAND day02_tests)
endif()
