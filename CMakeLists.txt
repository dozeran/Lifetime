
cmake_minimum_required(VERSION 3.20)

project(cpp_lab03_lifetime LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Build with AddressSanitizer and UBSan" OFF)

add_library(gallery
    src/photo.cpp
    src/visitor.cpp
)

target_include_directories(gallery PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(gallery PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

if(ENABLE_SANITIZERS)
    target_compile_options(gallery PRIVATE
        -fsanitize=address,undefined
        -g
    )
    target_link_options(gallery INTERFACE
        -fsanitize=address,undefined
    )
endif()

add_executable(lifetime_demo
    src/lifetime_demo.cpp
)

target_link_libraries(lifetime_demo PRIVATE gallery)

target_compile_options(lifetime_demo PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

if(ENABLE_SANITIZERS)
    target_compile_options(gallery PRIVATE
        -fsanitize=address,undefined
        -g
    )
    target_link_options(gallery INTERFACE
        -fsanitize=address,undefined
    )
endif()

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
    )

    FetchContent_MakeAvailable(googletest)

    add_executable(photo_tests
        tests/photo_test.cpp
    )

    target_link_libraries(photo_tests
        PRIVATE
        gallery
        GTest::gtest_main
    )

    target_compile_options(photo_tests PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

        if(ENABLE_SANITIZERS)
        target_compile_options(photo_tests PRIVATE
            -fsanitize=address,undefined
            -g
        )
        target_link_options(photo_tests PRIVATE
            -fsanitize=address,undefined
        )
    endif()

    include(GoogleTest)
    gtest_discover_tests(photo_tests)
endif()