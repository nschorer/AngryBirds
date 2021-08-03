#include "RedBird.h"

PhysicsFixture RedBird::fixture(Shape::Circle, 30.0f, 0.3f, 0.2f, FilterCategory::BIRD);
float RedBird::width = 46.0f;
float RedBird::height = 45.0f;
ImageName::Name RedBird::imgNames[] = { ImageName::Name::Bird_Red_Normal, ImageName::Name::Bird_Red_Blink, ImageName::Name::Bird_Red_Flying, ImageName::Name::Bird_Red_Damaged };

RedBird::RedBird(float x, float y, PhysicsWorld* pWorld)
	:Bird_Base(GameObjectName::Bird_Red, x, y, width, height, &fixture, imgNames, pWorld)
{

}
