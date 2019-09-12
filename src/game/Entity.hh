#pragma once

#include <reactphysics3d.h>

namespace game {

  class Entity {
  public:
    Entity();

    void update();

  private:
    static const int nbRigidBodies = 4;

    reactphysics3d::DynamicsWorld dynamicsWorld;
    reactphysics3d::RigidBody* floor;
    reactphysics3d::RigidBody* rigidBodies[nbRigidBodies];
    reactphysics3d::ProxyShape* proxyShapes[nbRigidBodies];
    reactphysics3d::BallAndSocketJoint* joints[nbRigidBodies - 1];
  };
}
