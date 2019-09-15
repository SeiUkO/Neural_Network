#include <iostream>
#include "Entity.hh"

using namespace reactphysics3d;

namespace game {

  static CapsuleShape* getCapsuleShapeBase() {
    static CapsuleShape* capsuleShape = nullptr;
    if (capsuleShape == nullptr)
      capsuleShape = new CapsuleShape(1, 3);
    return capsuleShape;
  }

  static BoxShape* getFloorShapeBase() {
    static BoxShape* floorShape = nullptr;
    if (floorShape == nullptr)
      floorShape = new BoxShape(Vector3(1000, 1, 1000));
    return floorShape;
  }

  static void fillArrayFromMatrix(float* array, const Matrix3x3& m) {
    Vector3 v = m.getRow(0);
    array[0] = v.x;
    array[1] = v.y;
    array[2] = v.z;
    v = m.getRow(1);
    array[3] = v.x;
    array[4] = v.y;
    array[5] = v.z;
    v = m.getRow(2);
    array[6] = v.x;
    array[7] = v.y;
    array[8] = v.z;
  }

  Entity::Entity() : dynamicsWorld(DynamicsWorld(Vector3(0, -9.81, 0))) {

    dynamicsWorld.enableSleeping(false);
    Transform transform(Vector3(0, 2.5, 0), Quaternion::fromEulerAngles(0, 0, 0.0001));
    rigidBodies[0] = dynamicsWorld.createRigidBody(transform);
    rigidBodies[0]->setType(BodyType::DYNAMIC);
    transform = Transform(Vector3(0, 8.5, 0), Quaternion::fromEulerAngles(0, 0, 0.0001));
    rigidBodies[1] = dynamicsWorld.createRigidBody(transform);
    rigidBodies[1]->setType(BodyType::DYNAMIC);
    transform = Transform(Vector3(0, -1, 0), Quaternion::identity());
    floor = dynamicsWorld.createRigidBody(transform);
    floor->setType(BodyType::STATIC);

    transform = Transform(Vector3(0, 0, 0), Quaternion::identity());
    proxyShapes[0] = rigidBodies[0]->addCollisionShape(getCapsuleShapeBase(), transform, 1);
    proxyShapes[1] = rigidBodies[1]->addCollisionShape(getCapsuleShapeBase(), transform, 1);
    floor->addCollisionShape(getFloorShapeBase(), transform, 1);

    BallAndSocketJointInfo jointInfo(rigidBodies[0], rigidBodies[1], Vector3(0, 5.5, 0));
    joints[0] = dynamic_cast<rp3d::BallAndSocketJoint*>(dynamicsWorld.createJoint(jointInfo));
  }

  void Entity::update() {
    dynamicsWorld.update(0.0166666);
    std::cout << "body1 " << rigidBodies[0]->getTransform().to_string() << std::endl;
    std::cout << "body2 " << rigidBodies[1]->getTransform().to_string() << std::endl;
  }

  size_t Entity::getInputSize() {
    return nbRigidBodies * getInputUnitSize();
  }

  size_t Entity::getOutputSize() {
    return nbRigidBodies * getOutputUnitSize();
  }

  void Entity::fillInputLayer(float* layer) {
    for (int i = 0; i < nbRigidBodies; ++i) {
      Matrix3x3 m = rigidBodies[i]->getTransform().getOrientation().getMatrix();
      fillArrayFromMatrix(&(layer[i * getInputUnitSize()]), m);
    }
  }

  void Entity::fillOutputLayer(float* layer) {

  }

  size_t Entity::getInputUnitSize() {
    return (sizeof(float) + sizeof(float) * 9);
  }

  size_t Entity::getOutputUnitSize() {
    return (sizeof(float) * 3);
  }
}