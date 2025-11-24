cmake_minimum_required(VERSION 4.2.0)

project(linsolver
        VERSION 0.0.1
        DESCRIPTION "Linear Algebra Equation Solver"
        LANGUAGES CXX C
)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)



## ln -s build/compile_commands.json ../compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
    main.cpp
    linEquation.cpp
)
add_executable(linsolver  ${SOURCE})

