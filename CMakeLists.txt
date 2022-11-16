cmake_minimum_required(VERSION 3.16.3)

project(my_container)

set(SOURCES
    src/array_container.cpp
    src/doubly_linked_container.cpp
    src/linked_container.cpp
    src/main.cpp
)

add_executable(my_container ${SOURCES})

set_target_properties(my_container PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(my_container PRIVATE
    -g
    -Wall
    -Wextra
    -Werror
    -pedantic
)
