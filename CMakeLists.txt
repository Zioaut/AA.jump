cmake_minimum_required(VERSION 3.8)
project(AA_jump)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(SOURCE_FILES main.cpp Window.cpp Window.h Game.cpp Game.h Hero.cpp Hero.h Enemy.cpp Enemy.h Block.cpp Block.h Maps.cpp Maps.h Observer.h Subject.h Achievments.cpp Achievments.h DisplayElement.h StrategyMove.h StrategyDefense.h StrategyAtkLeft.h StrategyAtkRight.h)
add_executable(AA_jump ${SOURCE_FILES})


set(EXECUTABLE_NAME ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif ()
