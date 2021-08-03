#include "BigBird.h"

PhysicsFixture BigBird::fixture(Shape::Circle, 30.0f, 0.3f, 0.2f, FilterCategory::BIRD);
float BigBird::width = 98.0f;
float BigBird::height = 98.0f;
ImageName::Name BigBird::imgNames[] = { ImageName::Name::Bird_Big_Normal, ImageName::Name::Bird_Big_Blink, ImageName::Name::Bird_Big_Flying, ImageName::Name::Bird_Big_Damaged };

BigBird::BigBird(float x, float y, PhysicsWorld* pWorld)
	:Bird_Base(GameObjectName::Bird_Big, x, y, width, height, &fixture, imgNames, pWorld)
{
	mask_destroyMaterial = (int)MaterialMask::GLASS | (int)MaterialMask::STONE | (int)MaterialMask::WOOD;
}
