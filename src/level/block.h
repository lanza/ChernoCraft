#pragma once

#include "../graphics/shader.h"
#include "../graphics/texture.h"
#include "../graphics/vertexarray.h"
#include "../utils/glm.h"

class Block {
private:
  unsigned int ID;
  VertexArray *vao;
  Shader *shader;
  glm::vec3 color;

public:
  Block(unsigned int ID);
  void update();
  void render(glm::vec3 position);
};