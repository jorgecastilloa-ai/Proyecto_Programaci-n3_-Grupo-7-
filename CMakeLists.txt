cmake_minimum_required(VERSION 3.10)
project(proyectoProgra)

set(CMAKE_CXX_STANDARD 17)

add_executable(proyectoProgra
        main.cpp
        Database.cpp
        Movie.cpp
        Trie.cpp
        User.cpp
        Utils.cpp
)