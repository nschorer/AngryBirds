#include "BlueBird.h"
#include "PhysicsMaterial.h"
#include "GameObjectMan.h"
#include "DeathPoof.h"
#include "TimerMan.h"
#include "TimerEvent_DeleteGameObject.h"

PhysicsFixture BlueBird::fixture(Shape::Circle, 30.0f, 0.3f, 0.2f, FilterCategory::BIRD);
float BlueBird::width = 30.0f;
float BlueBird::height = 30.0f;
ImageName::Name BlueBird::imgNames[] = { ImageName::Name::Bird_Blue_Normal, ImageName::Name::Bird_Blue_Blink, ImageName::Name::Bird_Blue_Flying, ImageName::Name::Bird_Blue_Damaged };

BlueBird::BlueBird(float x, float y, PhysicsWorld* pWorld, bool isClone)
	:Bird_Base(GameObjectName::Bird_Blue, x, y, width, height, &fixture, imgNames, pWorld)
{
	mask_destroyMaterial = (int)MaterialMask::GLASS;
	usedSpecial = isClone;
}

void BlueBird::Special()
{
	BlueBird* pBird;
	Vect2D impulse(0.0f, 1.0f);

	b2Vec2 v = this->pPhysicsBody->GetB2Body()->GetLinearVelocity();

	pBird = new BlueBird(this->posX, this->posY + 30, this->pPhysicsBody->GetWorld(), true);
	GameObjectMan::Add(pBird, GameObjectName::Name::MainGroup);
	pBird->GetPhysicsBody()->GetB2Body()->SetLinearVelocity(v);
	pBird->ApplyImpulse(impulse);

	this->usedSpecial = true;

	impulse.y = -impulse.y;

	pBird = new BlueBird(this->posX, this->posY - 30, this->pPhysicsBody->GetWorld(), true);
	GameObjectMan::Add(pBird, GameObjectName::Name::MainGroup);
	pBird->GetPhysicsBody()->GetB2Body()->SetLinearVelocity(v);
	pBird->ApplyImpulse(impulse);

	GameObject2D* pPoof = new GameObject2D(GameObjectName::Puff, new GraphicsObject_Sprite(ImageName::Name::Puff, Rect(this->posX, this->posY, this->origWidth * 3, this->origHeight * 3)));
	GameObjectMan::Add(pPoof, GameObjectName::Name::MainGroup);
	TimerMan::AddEvent(0.75f, new TimerEvent_DeleteGameObject(pPoof));
}
