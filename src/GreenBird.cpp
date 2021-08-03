#include "GreenBird.h"

PhysicsFixture GreenBird::fixture(Shape::Circle, 30.0f, 0.3f, 0.2f, FilterCategory::BIRD);
float GreenBird::width = 99.0f;
float GreenBird::height = 72.0f;
ImageName::Name GreenBird::imgNames[] = { ImageName::Name::Bird_Green_Normal, ImageName::Name::Bird_Green_Blink, ImageName::Name::Bird_Green_Flying, ImageName::Name::Bird_Green_Damaged,
										  ImageName::Name::Bird_Green_Boomerang};

GreenBird::GreenBird(float x, float y, PhysicsWorld* pWorld)
	:Bird_Base(GameObjectName::Bird_Green, x, y, width, height, &fixture, imgNames, pWorld), boomerangOn(false)
{

}


void GreenBird::Update(float t)
{
	Bird_Base::Update(t);

	if (this->birdState == State::LAUNCHED || this->birdState == State::FREE) {
		if (boomerangOn)
		{
			Vect2D curve(-25.0f, 0.0f);
			this->ApplyForce(curve);
			this->SetAngle(this->currAngle - 0.25f);
		}
	}
}

void GreenBird::Special()
{
	boomerangOn = true;
	((GraphicsObject_Sprite*)this->GetGameSprite())->SetImage(imgNames[4]);
	this->birdState = State::FREE;
}

void GreenBird::OnCollide()
{
	if (birdState == State::FREE)
	{
		if (boomerangOn)
		{
			boomerangOn = false;
		}
		birdState = State::FREE;
	}

	Bird_Base::OnCollide();
}
