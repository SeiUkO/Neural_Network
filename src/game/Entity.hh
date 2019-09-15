#pragma once

#include <reactphysics3d.h>

namespace game {

  class Entity {
  public:
    Entity();

    void update();

    size_t getInputSize();

    size_t getOutputSize();

    void fillInputLayer(float* layer);

    void fillOutputLayer(float* layer);

  private:
    static const int nbRigidBodies = 4;

    static size_t getInputUnitSize();

    static size_t getOutputUnitSize();

    reactphysics3d::DynamicsWorld dynamicsWorld;
    reactphysics3d::RigidBody* floor;
    reactphysics3d::RigidBody* rigidBodies[nbRigidBodies];
    reactphysics3d::ProxyShape* proxyShapes[nbRigidBodies];
    reactphysics3d::BallAndSocketJoint* joints[nbRigidBodies - 1];
  };
}
