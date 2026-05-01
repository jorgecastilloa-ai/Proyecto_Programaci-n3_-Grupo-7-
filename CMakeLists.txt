cmake_minimum_required(VERSION 4.1)
project(proyectobeta)

set(CMAKE_CXX_STANDARD 20)

add_executable(proyectobeta main.cpp Database.cpp Database.h Movie.cpp Movie.h Trie.cpp Trie.h User.cpp User.h Utils.cpp Utils.h)
