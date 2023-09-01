cmake_minimum_required(VERSION 3.27)
project(example)

add_subdirectory(extern/pybind11)
pybind11_add_module(example example.cpp)
