#include "Floor.h"
#include "ContactAction.h"

PhysicsFixture Floor::fixture(Shape::Rectangle, 0.0f, 10.0f, 0.0f);

Floor::Floor(float x, float y, float width, float height, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Floor, new GraphicsObject_Sprite(ImageName::Null, Rect(x, y, width, height)), pWorld, BodyType::Static, &Floor::fixture)
{
	this->SetCollisionFlags((unsigned int)FilterCategory::FLOOR, (unsigned int)FilterCategory::ALL);
}

void Floor::CollideVisit(Bird_Base& other, b2Contact* pcontact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
		ContactAction::ContactPair(other, *this, pcontact, pImpulse);
}

void Floor::CollideVisit(WhiteBirdEgg& other, b2Contact* pcontact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
		ContactAction::ContactPair(other, *this, pcontact, pImpulse);
}
