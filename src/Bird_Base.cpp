#include "Bird_Base.h"
#include "ContactAction.h"
#include "Mouse.h"
#include "GameObjectMan.h"
#include "TimerMan.h"
#include "TimerEvent_DeleteGameObject.h"
#include "TimerEvent_Jump.h"
#include "TimerEvent_Blink.h"
#include "TimerEvent_Unblink.h"
#include "TimerEvent_KillBird.h"
#include "AngryCamera.h"
#include "DeathPoof.h"
#include "AudioManager.h"

Bird_Base::Bird_Base(GameObjectName::Name name, float x, float y, float width, float height, PhysicsFixture* pFixture, ImageName::Name _imgNames[4], PhysicsWorld* pWorld)
	:PhysicsObject2D(name, new GraphicsObject_Sprite(_imgNames[0], Rect(x, y, width, height)), pWorld, BodyType::Dynamic, pFixture), 
	imgNames(_imgNames), usedSpecial(false), triggerJump(false), eyeState(EyeState::OPEN), birdState(State::FREE), mask_2xMaterial(0), mask_destroyMaterial(0)
{
	//this->WaitInLine();
}

void Bird_Base::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void Bird_Base::CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	//if (pimpulse)
		ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void Bird_Base::CollideVisit(Floor& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void Bird_Base::CollideVisit(Bird_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void Bird_Base::Update(float t)
{
	GameObject2D::Update(t);


	switch (this->birdState)
	{
	case State::FREE:
	{
		break;
	}

	case State::IN_LINE:
	{

		ManageBlinkState();

		break;
	}
	case State::IN_SLING:
	{
		break;
	}
	case State::LAUNCHED:
	{
		GenerateSmokeTrail(t);
		BirdPoint();
		CheckForSpecial();

		break;
	}
	case State::COLLIDED:
	{

		break;
	}
	default:
	{
		assert(false && "Case not implemented.");
		break;
	}
	}

}

void Bird_Base::Special()
{
	// derived overrides this... or not
}

void Bird_Base::Jump()
{
	triggerJump = true;
}

void Bird_Base::Blink()
{
	eyeState = EyeState::CLOSE;
}

void Bird_Base::Unblink()
{
	eyeState = EyeState::OPEN;
}

void Bird_Base::Die()
{
	this->MarkForDelete();
	GameObjectMan::Add(new DeathPoof(*this), GameObjectName::Name::Effects);
	AudioManager::BirdSquawk();
}

void Bird_Base::WaitInLine()
{
	this->SetPhysicsActive(true);
	this->birdState = State::IN_LINE;
	this->SetCollisionFlags((unsigned int)FilterCategory::BIRD, (unsigned int)FilterCategory::FLOOR);

	float min = 3;
	float max = 5;
	float r = (float)rand() / (float)RAND_MAX;
	float t = min + r * (max - min);
	TimerMan::AddEvent(t, new TimerEvent_Jump(this));
}

void Bird_Base::LoadIntoSling()
{
	this->SetPhysicsActive(false);
	this->birdState = State::IN_SLING;
	this->SetCollisionFlags((unsigned int)FilterCategory::BIRD, (unsigned int)FilterCategory::ALL);

	GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();
	pSprite->SetImage(imgNames[(int)IMG_INDEX::NORMAL]);
}

void Bird_Base::Launch()
{
	this->SetPhysicsActive(true);
	this->birdState = State::LAUNCHED;
	this->SetCollisionFlags((unsigned int)FilterCategory::BIRD, (unsigned int)FilterCategory::ALL);

	AudioManager::BirdFlying();

	RecallSmokeTrail();

	GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();
	pSprite->SetImage(imgNames[(int)IMG_INDEX::FLYING]);
}

void Bird_Base::OnCollide()
{
	if (this->birdState == State::LAUNCHED) {
		//this->SetPhysicsActive(true);
		this->birdState = State::COLLIDED;
		this->SetCollisionFlags((unsigned int)FilterCategory::BIRD, (unsigned int)FilterCategory::ALL);

		GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();
		pSprite->SetImage(imgNames[(int)IMG_INDEX::DAMAGED]);

		AngryCamera::SetMode(AngryCamera::Mode::Collided);

		//TimerMan::AddEvent(10.0f, new TimerEvent_KillBird(this));
	}
}

void Bird_Base::ManageBlinkState()
{
	if (triggerJump)
	{
		this->SetPhysicsActive(true);
		Vect2D impulse(0.0f, 4.0f);
		this->ApplyImpulse(impulse);
		triggerJump = false;

		float min = 3;
		float max = 5;
		float r = (float)rand() / (float)RAND_MAX;
		float rand_t = min + r * (max - min);
		TimerMan::AddEvent(rand_t, new TimerEvent_Jump(this));
		AudioManager::BirdSquawk();
	}

	// blink
	if (eyeState == EyeState::OPEN)
	{
		GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();
		pSprite->SetImage(imgNames[(int)IMG_INDEX::NORMAL]);

		// queue blink
		float min = 1;
		float max = 4;
		float r = (float)rand() / (float)RAND_MAX;
		float rand_t = min + r * (max - min);
		TimerMan::AddEvent(rand_t, new TimerEvent_Blink(this));

		eyeState = EyeState::WAITING;
	}

	// unblink
	else if (eyeState == EyeState::CLOSE)
	{
		GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();
		pSprite->SetImage(imgNames[(int)IMG_INDEX::BLINK]);

		// queue unblink
		TimerMan::AddEvent(0.25f, new TimerEvent_Unblink(this));

		eyeState = EyeState::WAITING;
	}
}

void Bird_Base::BirdPoint()
{
	b2Body* pB2Body = this->GetPhysicsBody()->GetB2Body();

	// face in direction of flight
	float angle = atan2f(pB2Body->GetLinearVelocity().y, pB2Body->GetLinearVelocity().x);
	pB2Body->SetTransform(pB2Body->GetWorldCenter(), angle);
}

void Bird_Base::GenerateSmokeTrail(float t)
{
	//b2Body* pB2Body = this->pPhysicsBody->GetB2Body();
	static int count = 0;
	// smoke trail
	if (count > 5)
	{
		count = 0;
		float x = this->posX;
		float y = this->posY;

		GameObject2D* pPuff = new GameObject2D(GameObjectName::Puff, new GraphicsObject_Sprite(ImageName::Name::Puff, Rect(x, y, 30, 30)));
		GameObjectMan::Add(pPuff, GameObjectName::SmokeTrail);
		pPuff->Update(t);      // without this update, it'll sit at the origin for the first frame
		//TimerMan::AddEvent(0.5f, new TimerEvent_DeleteGameObject(pPuff));
	}
	count++;
}

void Bird_Base::CheckForSpecial()
{
	if (!usedSpecial && Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT))
	{
		usedSpecial = true;
		Special();
		AngryCamera::SetMode(AngryCamera::Mode::Collided);
	}
}

byte Bird_Base::Get2xMask()
{
	return mask_2xMaterial;
}

byte Bird_Base::GetDestroyMask()
{
	return mask_destroyMaterial;
}

void Bird_Base::BeginAwake(b2Body* _body)
{
	_body;
}

void Bird_Base::EndAwake(b2Body* _body)
{
	_body;
	//if (this->birdState == State::COLLIDED)
	//{
	//	//Trace::out("Dead!");
	//	Die();
	//}
}

void Bird_Base::RecallSmokeTrail()
{
	GameObject2D* pObj;
	GameObject2D* pObjNext;

	GameObject* pSort = GameObjectMan::Find(GameObjectName::Name::SmokeTrail);

	pObj = (GameObject2D*)pSort->getChild();

	while (pObj != nullptr)
	{
		pObjNext = (GameObject2D*)pObj->getSibling();

		pObj->MarkForDelete();

		pObj = pObjNext;
	}
}

void Bird_Base::CleanupBirds()
{
	GameObject2D* pObj;
	GameObject2D* pObjNext;

	Bird_Base* pBird;

	GameObject* pSort = GameObjectMan::Find(GameObjectName::Name::MainGroup);
	pObj = (GameObject2D*)pSort->getChild();

	while (pObj != nullptr)
	{
		pObjNext = (GameObject2D*)pObj->getSibling();

		pBird = (Bird_Base*)pObj;
		if (pBird->birdState == State::COLLIDED || pBird->birdState == State::FREE)
		{

			pObj->MarkForDelete();

		}

		pObj = pObjNext;
	}
}
