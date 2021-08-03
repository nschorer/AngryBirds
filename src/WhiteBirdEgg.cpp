#include "WhiteBirdEgg.h"
#include "Blast.h"
#include "GameObjectMan.h"
#include "ContactAction.h"
#include "TimerMan.h"
#include "TimerEvent_Blast.h"

PhysicsFixture WhiteBirdEgg::fixture(Shape::Circle, 3.0f, 0.6f, 0.5f);
float WhiteBirdEgg::width = 45.0f;
float WhiteBirdEgg::height = 58.0f;
ImageName::Name WhiteBirdEgg::imgName = ImageName::Name::Bird_White_Egg;

WhiteBirdEgg::WhiteBirdEgg(float x, float y, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Name::Bird_White_Egg, new GraphicsObject_Sprite(imgName, Rect(x, y, width, height)), pWorld, BodyType::Dynamic, &fixture)
{
}

void WhiteBirdEgg::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if(pimpulse)
	ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void WhiteBirdEgg::CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
	ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void WhiteBirdEgg::CollideVisit(Floor& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
	ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void WhiteBirdEgg::Break()
{
	TimerMan::AddEvent(0.0f, new TimerEvent_Blast(this->posX, this->posY));
	this->MarkForDelete();
}
