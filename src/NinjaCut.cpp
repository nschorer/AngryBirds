#include "NinjaCut.h"
#include "Box2DWrapper.h"
#include "GraphicsObject_Box.h"
#include "GameObjectMan.h"
#include "TimerMan.h"
#include "TimerEvent_DeleteGameObject.h"
#include "NinjaSwordCallback.h"
#include "PhysicsMan.h"

NinjaCut::NinjaCut(NinjaSwordCallback* pRCCB, Vect& start, Vect& end, float len)
	:GameObject2D(GameObjectName::Name::Alien, new GraphicsObject_Sprite(ImageName::Name::Bang, Rect(1, 1, len, 5)))
{
	Vect v = (end - start);
	//float len = MeterToPixel(v.Length());
	//float len = v.mag();
	Vect pos = .5f * (start + end);
	float ang = atan2f(v.Y(), v.X());

	this->origAngle = ang;
	this->posX = pos.X();
	this->posY = pos.Y();

	// Query the line
	b2World* pB2World = PhysicsMan::GetWorld()->GetWorld();
	b2Vec2 from(PixelToMeter(start.X()), PixelToMeter(start.Y()));
	b2Vec2 to(PixelToMeter(end.X()), PixelToMeter(end.Y()));

	pB2World->RayCast(pRCCB, from, to);
	pRCCB->ProcessList();

	TimerMan::AddEvent(0.1f, new TimerEvent_DeleteGameObject(this));
}