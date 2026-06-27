# Ad Maiorem Dei Gloriam!
cmake_minimum_required(VERSION 3.10)

project(AsciiBirdProject)

add_executable(AsciiBird)
target_sources(AsciiBird PRIVATE src/main.cpp)
target_include_directories(AsciiBird PRIVATE include/)