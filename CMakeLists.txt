cmake_minimum_required(VERSION 3.20)

project(application VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DUNICODE -D_UNICODE)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(application
    mainwindow.ui
    mainwindow.cpp
    main.cpp
)

target_link_libraries(application PRIVATE Qt6::Widgets)

set_target_properties(application PROPERTIES
    WIN32_EXECUTABLE ON
)

add_custom_command(TARGET application POST_BUILD
    COMMAND Qt6::windeployqt --$<IF:$<CONFIG:Debug>,debug,release> --dir "${CMAKE_CURRENT_BINARY_DIR}" "$<TARGET_FILE_DIR:application>/$<TARGET_FILE_NAME:application>"
)
