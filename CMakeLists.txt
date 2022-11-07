cmake_minimum_required(VERSION 3.23)
project(CardWar)

set(CMAKE_CXX_STANDARD 14)

add_executable(CardWar main.cpp InputOutput.cpp play.cpp test.cpp mystack.h card.h)
