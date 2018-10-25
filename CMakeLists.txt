cmake_minimum_required(VERSION 3.12)
project(PROJECT2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROJECT2
        .idea/codeStyles/Project.xml
        .idea/misc.xml
        .idea/modules.xml
        .idea/PROJECT2.iml
        .idea/vcs.xml
        .idea/workspace.xml
        documents/report.docx
        .gitignore
        main.cpp BuildBST.c BuildBST.h)
