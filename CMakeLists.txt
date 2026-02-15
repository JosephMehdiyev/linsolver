cmake_minimum_required(VERSION 4.2.0)

project(linsolver
        VERSION 0.0.1
        DESCRIPTION "Personal Computation Library"
        LANGUAGES CXX C
)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

include_directories(${linsolver_SOURCE_DIR}/dataStructure)


## ln -s build/compile_commands.json ../compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
    main.cpp
    linEquation.cpp
    dataStructure/Mat.hpp
)
add_executable(linsolver  ${SOURCE})
target_include_directories(linsolver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/dataStructure)

