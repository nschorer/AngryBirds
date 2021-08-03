#include "BlackBird.h"

#include "GameObjectMan.h"
#include "Blast.h"
#include "TimerEvent.h"

PhysicsFixture BlackBird::fixture(Shape::Circle, 30.0f, 0.3f, 0.2f, FilterCategory::BIRD);
float BlackBird::width = 61.0f;
float BlackBird::height = 81.0f;
ImageName::Name BlackBird::imgNames[] = { ImageName::Name::Bird_Black_Normal, ImageName::Name::Bird_Black_Blink, ImageName::Name::Bird_Black_Flying, ImageName::Name::Bird_Black_Damaged,
										  ImageName::Name::Bird_Black_Bomb_0, ImageName::Name::Bird_Black_Bomb_1, ImageName::Name::Bird_Black_Bomb_2 };

BlackBird::BlackBird(float x, float y, PhysicsWorld* pWorld)
	:Bird_Base(GameObjectName::Bird_Black, x, y, width, height, &fixture, imgNames, pWorld), bombCount(0)
{

}

void BlackBird::Update(float t)
{
	Bird_Base::Update(t);

	int timeToBlow = 20;

	if (bombCount > 0 && bombCount < timeToBlow) {
		GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();

		if (bombCount == 1)
		{
			pSprite->SetImage(imgNames[4]);
		}
		else if (bombCount == timeToBlow / 3)
		{
			pSprite->SetImage(imgNames[5]);
		}
		else if (bombCount == timeToBlow * 2 / 3)
		{
			pSprite->SetImage(imgNames[6]);
		}
		bombCount++;
	}
	else if (bombCount >= timeToBlow)
	{
		Explode();
	}
}

void BlackBird::Special()
{
	bombCount = 1;
}

void BlackBird::Explode()
{
	GameObject* pObj = new Blast(this->posX, this->posY, this->pPhysicsBody->GetWorld());
	GameObjectMan::Add(pObj, GameObjectName::Name::Effects);
	this->MarkForDelete();
}

void BlackBird::OnCollide()
{

	if (birdState == State::LAUNCHED) {
		if (!usedSpecial)
		{
			Special();
		}
		birdState = State::LAUNCHED;
	}

	Bird_Base::OnCollide();
}
