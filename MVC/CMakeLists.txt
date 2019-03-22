cmake_minimum_required(VERSION 3.13)
project(BattleshipMVC)

set(CMAKE_CXX_STANDARD 14)
#add_subdirectory(CursesWrapper)

add_library(BattleshipMVC STATIC
        Controller.cpp Controller.h
        Board.cpp Board.h
        Cell.h Cell.cpp
        GameAttributes.h GameAttributes.cpp
        ShipPlacement.h ShipPlacement.cpp
        Player.cpp Player.h
        HumanPlayer.cpp HumanPlayer.h AiPlayer.cpp AiPlayer.h Model.cpp Model.h)
target_include_directories(BattleshipMVC PUBLIC .)
#target_link_libraries(BattleshipMVC PUBLIC CursesWrapper)
target_compile_options(BattleshipMVC PRIVATE ${BATTLESHIP_COMPILE_OPTIONS})
target_compile_definitions(BattleshipMVC PRIVATE DEFAULT_CONFIGURATION_LOCATION="${CMAKE_SOURCE_DIR}/GameConfigurations/DefaultConfiguration.txt")
