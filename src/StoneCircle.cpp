#include "StoneCircle.h"
#include "StoneMaterial.h"

PhysicsFixture StoneCircle::fixture(Shape::Circle, *StoneMaterial::Instance());
float StoneCircle::width = 76.0f;
float StoneCircle::height = 76.0f;
ImageName::Name StoneCircle::imgNames[] = { ImageName::Name::Stone_Circle_0, ImageName::Name::Stone_Circle_1, ImageName::Name::Stone_Circle_2, ImageName::Name::Stone_Circle_3 };

StoneCircle::StoneCircle(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Stone_Circle, x, y, width, height, &fixture, imgNames, StoneMaterial::Instance(), pWorld)
{

}
