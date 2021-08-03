#include "Blast.h"
#include "ContactAction.h"

#include "BlocksHeader.h"
#include "GameObjectMan.h"
#include "TimerMan.h"
#include "TimerEvent_DeleteGameObject.h"

PhysicsFixture Blast::fixture(Shape::Circle);
ImageName::Name Blast::image = ImageName::Null;
float Blast::width = 200.0f;
float Blast::height = 200.0f;

Blast::Blast(float x, float y, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Bang, new GraphicsObject_Sprite(image, Rect(x, y, Blast::width, Blast::height)), pWorld, BodyType::Static, &Blast::fixture)
{
	GameObject2D* pBangSprite;
	pBangSprite = new GameObject2D(GameObjectName::Name::Bang, new GraphicsObject_Sprite(ImageName::Name::Bang, Rect(x, y, width / 3, height / 3)));
	GameObjectMan::Add(pBangSprite, GameObjectName::Slong_Handle_Front);
	TimerMan::AddEvent(1.0f, new TimerEvent_DeleteGameObject(pBangSprite));

	TimerMan::AddEvent(0.5f, new TimerEvent_DeleteGameObject(this));
}

void Blast::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	//if (pimpulse)
	ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void Blast::CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	//if (pimpulse)
	ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}
