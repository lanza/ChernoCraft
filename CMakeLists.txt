cmake_minimum_required(VERSION 3.19)

project(ChernoCraft CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED PATH /usr/local/opt/sdl2/lib/cmake)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)

include(FindPkgConfig)
pkg_check_modules(SDL2_image REQUIRED SDL2_image)

add_executable(
  ChernoCraft
  src/entity/entity.cpp
  src/entity/player.cpp
  src/game.cpp
  src/graphics/screen.cpp
  src/graphics/shader.cpp
  src/graphics/texture.cpp
  src/graphics/vertexarray.cpp
  src/input.cpp
  src/level/block/air_block.cpp
  src/level/block/block.cpp
  src/level/block/dirt.cpp
  src/level/block/dirt_block.cpp
  src/level/block/stone.cpp
  src/level/block/stone_block.cpp
  src/level/level.cpp
  src/main.cpp
)

add_definitions(-DGL_SILENCE_DEPRECATION)

include(/Users/lanza/.dotfiles/cmake/Utilities.cmake)

log_variable(SDL2_image_INCLUDE_DIRS)

target_include_directories(ChernoCraft
  PUBLIC
  /usr/local/include
  ${SDL2_image_INCLUDE_DIRS})

target_link_libraries(ChernoCraft
  PUBLIC
  OpenGL::GL
  SDL2::SDL2
  glm::glm
  ${SDL2_image_LINK_LIBRARIES})
