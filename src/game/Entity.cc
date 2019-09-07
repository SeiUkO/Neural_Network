#include <iostream>
#include "Entity.hh"

using namespace reactphysics3d;

namespace game {

  CapsuleShape Entity::capsuleShape = CapsuleShape(1, 3);
  //BoxShape Entity::boxShape;

  Entity::Entity()
          : dynamicsWorld(DynamicsWorld(Vector3(0, -9.81, 0))) {

    auto *box = new BoxShape(Vector3(1000, 1, 1000));
    Transform transform(Vector3(0, 2.5, 0), Quaternion::identity());
    body1 = dynamicsWorld.createRigidBody(transform);
    body1->setType(BodyType::DYNAMIC);
    transform = Transform(Vector3(0, 8.5, 0), Quaternion::identity());
    body2 = dynamicsWorld.createRigidBody(transform);
    body2->setType(BodyType::DYNAMIC);
    transform = Transform(Vector3(0, -1, 0), Quaternion::identity());
    floor = dynamicsWorld.createRigidBody(transform);
    floor->setType(BodyType::STATIC);

    transform = Transform(Vector3(0, 0, 0), Quaternion::identity());
    proxyShape1 = body1->addCollisionShape(&capsuleShape, transform, 1);
    proxyShape2 = body2->addCollisionShape(&capsuleShape, transform, 1);
    proxyShape2 = floor->addCollisionShape(box, transform, 1);

    BallAndSocketJointInfo jointInfo(body1, body2, Vector3(0, 5.5, 0));
    joint = dynamic_cast<rp3d::BallAndSocketJoint *>(dynamicsWorld.createJoint(jointInfo));
  }

  void Entity::update() {
    dynamicsWorld.update(0.0166666);
    std::cout << "body1 " << body1->getTransform().to_string() << std::endl;
    std::cout << "floor " << floor->getTransform().to_string() << std::endl;
  }
}