#include "DeathZone.h"
#include "ContactAction.h"

PhysicsFixture DeathZone::fixture(Shape::Rectangle);
ImageName::Name DeathZone::image = ImageName::Null;

DeathZone::DeathZone(float x, float y, float width, float height, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::DeathZone, new GraphicsObject_Sprite(image, Rect(x, y, width, height)), pWorld, BodyType::Static, &fixture)
{
}

void DeathZone::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}
