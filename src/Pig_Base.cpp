#include "Pig_Base.h"
#include "ContactAction.h"
#include "PigTracker.h"
#include "AudioManager.h"
#include "GameObjectMan.h"
#include "DeathPoof.h"
#include "TimerMan.h"
#include "TimerEvent_DeleteGameObject.h"
#include "TimerEvent_DeleteJoint.h"

Pig_Base::Pig_Base(GameObjectName::Name name, float x, float y, float width, float height, PhysicsFixture* pFixture, float _maxHealth, ImageName::Name _imgNames[2], PhysicsWorld* pWorld)
	:PhysicsObject2D(name, new GraphicsObject_Sprite(_imgNames[0], Rect(x, y, width, height)), pWorld, BodyType::Dynamic, pFixture), 
	imgNames(_imgNames), maxHealth(_maxHealth), health(_maxHealth), pJoint(nullptr)
{
	PigTracker::PigBorn();
}

Pig_Base::~Pig_Base()
{
	PigTracker::PigKilled();
}

void Pig_Base::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Pig_Base::CollideVisit(Bird_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Pig_Base::CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void Pig_Base::CollideVisit(WhiteBirdEgg& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Pig_Base::CollideVisit(Blast& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	//if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Pig_Base::CollideVisit(DeathZone& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}


void Pig_Base::DoDamage(float damage)
{
	health -= damage;

	GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();

	if (health > maxHealth * 0.5f)
	{
		pSprite->SetImage(this->imgNames[0]);
	}
	else if (health > 0)
	{
		pSprite->SetImage(this->imgNames[1]);
	}
	else {
		Die();
	}
}

void Pig_Base::DestroyJoint()
{

	if (pJoint)
	{
		TimerEvent* pEvent = new TimerEvent_DeleteJoint(pJoint);
		TimerMan::AddEvent(0, pEvent);
		pJoint = nullptr;
	}
	
}





void Pig_Base::Die()
{
	//this->MarkForDelete();
	TimerMan::AddEvent(0.0f, new TimerEvent_DeleteGameObject(this));
	GameObjectMan::Add(new DeathPoof(*this), GameObjectName::Name::Effects);
	AudioManager::PigDie();
	//PigTracker::PigKilled();
}
