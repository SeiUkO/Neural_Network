#pragma once

#include <reactphysics3d.h>

namespace game {

  class Entity {
  public:
    Entity();
    void update();

  private:
    reactphysics3d::DynamicsWorld dynamicsWorld;
    reactphysics3d::RigidBody *body1;
    reactphysics3d::RigidBody *body2;
    reactphysics3d::RigidBody *floor;
    reactphysics3d::ProxyShape *proxyShape1;
    reactphysics3d::ProxyShape *proxyShape2;
    reactphysics3d::BallAndSocketJoint *joint;

    static reactphysics3d::CapsuleShape capsuleShape;
    static reactphysics3d::BoxShape boxShape;
  };
}
