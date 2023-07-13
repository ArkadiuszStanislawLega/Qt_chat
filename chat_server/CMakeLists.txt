cmake_minimum_required(VERSION 3.14)

project(chat_server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network Core)

add_executable(chat_server
  main.cpp
  server.h
  server.cpp
)
target_link_libraries(chat_server Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS chat_server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
