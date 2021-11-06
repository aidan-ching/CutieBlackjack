CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(blackjack
  card.hpp
  dealer.hpp
  game.hpp
  main.cpp
  player.hpp
  )
