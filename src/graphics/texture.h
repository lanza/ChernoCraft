#pragma once

#include <iostream>
#include <string>

#include <OpenGL/gl3.h>
#include <SDL.h>
#include <SDL_image.h>

class Texture {
public:
  // Static textures go here
  static Texture *dirt, *stone;

private:
  GLuint texture;
  GLuint load(std::string filepath);

public:
  Texture(std::string file);
  static void DESTROY();
  static void LOAD();
  void enable();
  void disable();
};
