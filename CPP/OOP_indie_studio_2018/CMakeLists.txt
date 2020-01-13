cmake_minimum_required(VERSION 3.9)
project(bomberman)

cmake_policy(SET CMP0074 NEW)
#Check OS
if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif (CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/tools)

if (WINDOWS)
    set(CMAKE_GENERATOR_PLATFORM "Visual Studio 15 2017 Win64")
    set(CMAKE_CXX_FLAGS "/w /std:c++14 /D_CRT_SECURE_NO_WARNINGS /wd4005 /wd4996 /nologo")
    set(BOOST_ROOT "C:/local/boost_1_66_0")
    set(BOOST_LIBRARYDIR "C:/local/boost_1_66_0/lib64-msvc-14.1")
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREADED OFF)
    set(Boost_USE_STATIC_RUNTIME OFF)
    find_package(X11)
    find_package(OpenGL)
    find_package(ZLIB)
    set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/tools/SFML")
    find_package(Irrlicht REQUIRED)
    link_libraries(Irrlicht)
    message(${Irrlicht_INCLUDE_DIRS})
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools/SFML/cmake/Modules")
    find_package(SFML 2.4 COMPONENTS audio REQUIRED)
    message(${SFML_INCLUDE_DIR})
    find_package(Boost 1.66 COMPONENTS system filesystem REQUIRED)
    if (Boost_FOUND)
        link_directories(${Boost_LIBRARY_DIRS})
        include_directories(${Boost_INCLUDE_DIRS})
    else ()
        MESSAGE(FATAL_ERROR "Boost library not found, thanks to install it")
    endif ()
else ()
    find_package(Irrlicht REQUIRED)
    message(${Irrlicht_INCLUDE_DIRS})
    MESSAGE(STATUS "HOME = $ENV{HOME}")
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -I. -lX11 -lXxf86vm -lXext -lGL -lIrrlicht -lboost_system -lboost_filesystem")
    find_package(Boost 1.66 COMPONENTS system filesystem REQUIRED)
    if (Boost_FOUND)
        link_directories(${Boost_LIBRARY_DIRS})
        include_directories(${Boost_INCLUDE_DIRS})
    else ()
        MESSAGE(FATAL_ERROR "Boost library not found, thanks to install it")
    endif ()
    find_package(SFML 2.4 COMPONENTS audio REQUIRED)
endif ()

include_directories(${Irrlicht_INCLUDE_DIRS}/.. ${PROJECT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/tools/SFML/include)
if (WINDOWS)
    link_directories("${PROJECT_SOURCE_DIR}/platforms/win")
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/platforms/win)
    file(GLOB_RECURSE source_files src/*.cpp)
    add_executable(bomberman ${source_files})
elseif (LINUX)
    link_directories("${PROJECT_SOURCE_DIR}")
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
    file(GLOB_RECURSE source_files src/*.cpp)
    add_executable(bomberman ${source_files})
    #    add_custom_command(
    #            TARGET bomberman POST_BUILD
    #            COMMAND ${CMAKE_COMMAND} -E copy
    #            ${PROJECT_SOURCE_DIR}/assets/*
    #            $ENV{HOME}/Indi_Studio/assets)
elseif (MACOS)
    link_directories("${PROJECT_SOURCE_DIR}/platforms/macos ")
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/platforms/macos)
endif ()

if (WINDOWS)
    if (CMAKE_CL_64)
        target_link_libraries(bomberman DBRx64 ${Irrlicht_LIBRARIES}
                ${X11_LIBRARIES}
                ${OPENGL_LIBRARIES}
                ${ZLIB_LIBRARIES}
                ${X11_Xxf86vm_LIB} ${Boost_LIBRARIES} Irrlicht sfml-audio)
    else ()
        target_link_libraries(bomberman DBRx86 ${Irrlicht_LIBRARIES}
                ${X11_LIBRARIES}
                ${OPENGL_LIBRARIES}
                ${ZLIB_LIBRARIES}
                ${X11_Xxf86vm_LIB} ${Boost_LIBRARIES} sfml-audio)
    endif ()
else ()
    target_link_libraries(bomberman ${Irrlicht_LIBRARIES}
            ${X11_LIBRARIES}
            ${OPENGL_LIBRARIES}
            ${ZLIB_LIBRARIES}
            ${X11_Xxf86vm_LIB} ${Boost_LIBRARIES} sfml-audio)
endif ()