cmake_minimum_required(VERSION 3.26)
project(TIZD)

set(CMAKE_CXX_STANDARD 17)

add_executable(TIZD
        menu/MenuItem.cpp
        lr_1.cpp
        menu/MenuItem.h
        menu/MenuManager.cpp
        menu/MenuManager.h
        lr_1.cpp
        linked_list/LinkedList.cpp
        linked_list/Node.cpp
        linked_list/LinkedList.h
        linked_list/Node.h
        exceptions/exceptions.h
)
