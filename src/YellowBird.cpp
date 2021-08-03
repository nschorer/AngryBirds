#include "YellowBird.h"

PhysicsFixture YellowBird::fixture(Shape::Circle, 30.0f, 0.3f, 0.2f, FilterCategory::BIRD);
float YellowBird::width = 58.0f;
float YellowBird::height = 54.0f;
ImageName::Name YellowBird::imgNames[] = { ImageName::Name::Bird_Yellow_Normal, ImageName::Name::Bird_Yellow_Blink, ImageName::Name::Bird_Yellow_Flying, ImageName::Name::Bird_Yellow_Damaged,
										   ImageName::Name::Bird_Yellow_Zoom};

YellowBird::YellowBird(float x, float y, PhysicsWorld* pWorld)
	:Bird_Base(GameObjectName::Bird_Yellow, x, y, width, height, &fixture, imgNames, pWorld), zoomCount(0)
{
	//mask_2xMaterial = (int)MaterialMask::WOOD;
}

void YellowBird::Update(float t)
{
	Bird_Base::Update(t);

	switch (birdState)
	{
	case State::LAUNCHED:
	{
		int zoomDone = 60;

		if (zoomCount > 0 && zoomCount < zoomDone )
		{
			zoomCount++;
		}
		else if (zoomCount >= zoomDone)
		{
			((GraphicsObject_Sprite*)this->GetGameSprite())->SetImage(imgNames[0]);
			zoomCount = 0;
			mask_destroyMaterial = 0;
		}

		break;
	}
	case State::COLLIDED:
		int zoomDone = 60;

		if (zoomCount > 0 && zoomCount < zoomDone)
		{
			zoomCount++;
		}
		else if (zoomCount >= zoomDone)
		{
			zoomCount = 0;
			mask_destroyMaterial = 0;
		}
	}
}

void YellowBird::Special()
{
	b2Vec2 v = this->GetPhysicsBody()->GetB2Body()->GetLinearVelocity();
	v.Normalize();
	Vect vb(v.x, 0.0, 0.0f);
	vb *= 4;
	Vect2D vc(vb.X(), vb.Y());

	this->ApplyImpulse(vc);
	
	((GraphicsObject_Sprite*)this->GetGameSprite())->SetImage(imgNames[4]);
	mask_destroyMaterial = (int)MaterialMask::WOOD;

	zoomCount = 1;
}
