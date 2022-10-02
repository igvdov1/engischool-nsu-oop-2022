cmake_minimum_required(VERSION 3.20)
project(complex_digitals)

set(CMAKE_CXX_STANDARD 17)

add_executable(complex_digitals main.cpp ComplexDigital.cpp ComplexDigital.h)
if (MSVC)
    target_compile_options(complex_digitals
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(complex_digitals
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()