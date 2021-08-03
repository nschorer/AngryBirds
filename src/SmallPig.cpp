#include "SmallPig.h"


PhysicsFixture SmallPig::fixture(Shape::Circle, 20.0f, 0.3f, 0.5f);
float SmallPig::width = 48.0f;
float SmallPig::height = 46.0f;
ImageName::Name SmallPig::imgNames[] = { ImageName::Name::Pig_Small_0, ImageName::Name::Pig_Small_1 };
float SmallPig::maxHealth = 300.0f;

SmallPig::SmallPig(float x, float y, PhysicsWorld* pWorld)
	:Pig_Base(GameObjectName::Name::Pig_Small, x, y, width, height, &fixture, maxHealth, imgNames, pWorld)
{

}

