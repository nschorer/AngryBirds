#include "WhiteBird.h"
#include "GameObjectMan.h"
#include "WhiteBirdEgg.h"


PhysicsFixture WhiteBird::fixture(Shape::Circle, 30.0f, 0.3f, 0.2f, FilterCategory::BIRD);
float WhiteBird::width = 81.0f;
float WhiteBird::height = 93.0f;
ImageName::Name WhiteBird::imgNames[] = { ImageName::Name::Bird_White_Normal, ImageName::Name::Bird_White_Blink, ImageName::Name::Bird_White_Flying, ImageName::Name::Bird_White_Damaged,
										  ImageName::Name::Bird_White_Laying, ImageName::Name::Bird_White_Egg, ImageName::Bird_White_Ghost};

WhiteBird::WhiteBird(float x, float y, PhysicsWorld* pWorld)
	:Bird_Base(GameObjectName::Bird_White, x, y, width, height, &fixture, imgNames, pWorld)
{

}

void WhiteBird::Special()
{
	Vect2D impulse(15.0f, 15.0f);
	this->ApplyImpulse(impulse);
	this->OnCollide();
	((GraphicsObject_Sprite*)this->GetGameSprite())->SetImage(imgNames[4]);
	this->SetCollisionFlags((unsigned int)FilterCategory::BIRD, 0);

	WhiteBirdEgg* pEgg = new WhiteBirdEgg(this->posX, this->posY - 20.0f, this->GetPhysicsBody()->GetWorld());
	GameObjectMan::Add(pEgg, GameObjectName::Name::MainGroup);
}
