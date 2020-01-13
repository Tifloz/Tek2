cmake_minimum_required(VERSION 3.2)
project(MyGKrellm)

set(CMAKE_CXX_FLAGS "-lncurses -std=c++14 ${CMAKE_CXX_FLAGS}")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CURSES_NEED_NCURSES TRUE)
set(SOURCE_FILES Qt/main.cpp Qt/include/window.hpp Qt/core/window.cpp Qt/include/gui_template.hpp
        Qt/core/CPU.cpp Qt/include/CPU.hpp Qt/core/Chart.cpp Qt/include/Chart.hpp
        Qt/core/RAM.cpp Qt/include/RAM.hpp src/modules/dateModule.cpp src/modules/dateModule.hpp
        src/modules/systemModule.cpp src/modules/systemModule.hpp src/modules/userModule.cpp
        src/modules/userModule.hpp src/IMonitorModule.hpp Qt/include/Network.hpp src/modules/cpuModule.cpp src/modules/cpuModule.hpp
        src/modules/ramModule.cpp src/modules/ramModule.hpp src/modules/baseModule.cpp src/modules/baseModule.hpp
        src/ncurses/Cpu.cpp src/ncurses/Cpu.hpp src/ncurses/Date.cpp src/ncurses/Date.hpp
        src/ncurses/Ram.cpp src/ncurses/Ram.hpp src/ncurses/startText.cpp  src/ncurses/System.cpp src/ncurses/System.hpp
        src/ncurses/SystemCore.cpp src/ncurses/SystemCore.hpp  src/ncurses/User.cpp src/ncurses/User.hpp
        src/IMonitorDisplay.hpp)
include_directories(Qt/include src/modules)
add_executable(MyGKrellm ${SOURCE_FILES})
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
qt5_use_modules(MyGKrellm Core Widgets Gui Charts)