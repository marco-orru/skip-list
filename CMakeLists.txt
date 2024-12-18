cmake_minimum_required(VERSION 3.20)
project("Skip List" C)

# Set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler-specific flags and options
if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2 /GL")
elseif (CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Ofast -march=native")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wextra -Wpedantic)
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Ofast -march=native -flto")
endif()

# Source files
file(GLOB LIB_SOURCES "source/library/*.c")
file(GLOB LIB_UNITY "vendor/unity/src/*.c")

# Executables
add_executable(skiplist "source/main.c" ${LIB_SOURCES})
add_executable(skiplist_tests "source/tests_main.c" ${LIB_SOURCES} ${LIB_UNITY})


# Include directories
target_include_directories(skiplist PRIVATE "source/library")
target_include_directories(skiplist_tests PRIVATE "source/library" "vendor/unity/src")