#pragma once

#include <vector>
#include "Entity.hh"

namespace game {
  class Game {
  private:
    std::vector<Entity> entities;

  public:
    void run();
  };
}

