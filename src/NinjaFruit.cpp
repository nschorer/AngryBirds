#include "NinjaFruit.h"
#include "GameObjectMan.h"

PhysicsFixture NinjaFruit::fixture(Shape::Circle, 10.0f, 0.3f, 0.5f);

NinjaFruit::NinjaFruit(GameObjectName::Name name, float x, float y, float _radius, int _score, ImageName::Name _imgNames[3], PhysicsWorld* pWorld)
	:PhysicsObject2D(name, new GraphicsObject_Sprite(_imgNames[0], Rect(x, y, 2 * _radius, 2 * _radius)), pWorld, BodyType::Dynamic, &fixture), imgNames(_imgNames), radius(_radius), score(_score)
{
	this->SetCollisionFlags(0, 0);
	ignoreRaycast = false;
}

void NinjaFruit::OnCut()
{
	this->MarkForDelete();

	PhysicsObject2D* pObj;
	float fruitX = this->posX;
	float fruitY = this->posY;
	Vect2D impulse(-2.0f, 0.0f);
	float cutRadius = radius * 1.4f;

	pObj = new PhysicsObject2D(this->GetName(), new GraphicsObject_Sprite(imgNames[1], Rect(fruitX-25, fruitY, cutRadius, cutRadius)), this->pPhysicsBody->GetWorld(), BodyType::Dynamic, &fixture);
	GameObjectMan::Add(pObj, GameObjectName::Name::MainGroup);
	pObj->SetCollisionFlags(0, 0);
	pObj->ApplyImpulse(impulse);

	pObj = new PhysicsObject2D(this->GetName(), new GraphicsObject_Sprite(imgNames[2], Rect(fruitX+25, fruitY, cutRadius, cutRadius)), this->pPhysicsBody->GetWorld(), BodyType::Dynamic, &fixture);
	GameObjectMan::Add(pObj, GameObjectName::Name::MainGroup);
	pObj->SetCollisionFlags(0, 0);
	impulse.x *= -1;
	pObj->ApplyImpulse(impulse);

	Trace::out("\n+%i", this->score);
}
