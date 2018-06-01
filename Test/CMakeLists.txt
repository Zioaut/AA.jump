cmake_minimum_required(VERSION 3.8)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(RunTest Test.cpp TestHero.cpp TestBlock.cpp TestEnemy.cpp TestMap.cpp)
target_link_libraries(RunTest ${GTEST_BOTH_LIBRARIES} core pthread)

set(CMAKE_MODULE_PATH "/home/francesco/CLionProject/AA.jump/Test/cmake_mod" ${CMAKE_MODULE_PATH}})
find_package(SFML 2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(RunTest ${SFML_LIBRARIES})
endif ()