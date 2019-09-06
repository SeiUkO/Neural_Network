#pragma once

#include "Action.hh"

namespace game {

  class Controller {
  public:
    Action get_move();
  };

}