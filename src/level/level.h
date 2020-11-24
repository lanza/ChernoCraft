#pragma once

#include <OpenGL/gl3.h>
#include <vector>

#include "../entity/entity.h"
#include "../entity/player.h"
#include "../graphics/shader.h"
#include "../graphics/vertexarray.h"
#include "../utils/glm.h"
#include "block/block.h"

class Level {
public:
  static unsigned short NULL_BLOCK;

private:
  VertexArray *floor;
  unsigned short ***blocks;
  glm::mat4 floor_pos, floor_rot;
  std::vector<Entity *> entities;

  const int WIDTH = 16;
  const int DEPTH = 16;
  const int HEIGHT = 16;
  glm::vec3 NULL_COORD = glm::vec3(-1.0, -1.0, -1.0);
  glm::vec3 selected_block;

public:
  Level();
  ~Level();
  void add(Entity *entity);
  void update();
  void select_block(glm::vec3 block);
  unsigned short &get_intersecting_block(Entity *entity);
  unsigned short &get_block(glm::vec3 position);
  unsigned short &raycast_collision(glm::vec3 position, glm::vec3 rotation);
  unsigned short &pick_block(glm::vec3 position, glm::vec3 &rotation);
  unsigned short &raycast_block_id(glm::vec3 position, glm::vec3 &rotation);
  unsigned short &raycast_block_id(glm::vec3 position, glm::vec3 &rotation,
                                   float distance);
  unsigned short &raycast_pre_block_id(glm::vec3 position, glm::vec3 &rotation);
  glm::vec3 raycast_block(glm::vec3 position, glm::vec3 &rotation);
  void render();
};
