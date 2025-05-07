# set minimul reuired version
cmake_minimum_required(VERSION 3.31)
project(ReatTimePipeline)

# specifies c++ version
set(CMAKE_CXX_STANDARD 17)

# avoid fallback to older version
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ouput directories  complete all executables in bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#inlcude
include_directories(include)

# Add main executable

add_executable(realTimePipeline
    src/main.cpp    
)

# enable_testing()
# add_subdirectory(tests)