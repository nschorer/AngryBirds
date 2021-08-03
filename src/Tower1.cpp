#include "Tower1.h"
#include "PhysicsObject2D.h"
#include "GameObjectMan.h"
#include "BlocksHeader.h"
#include "WoodPlatform.h"
#include "BirdsPigsHeader.h"

void Tower1(float x, float y, PhysicsWorld* pWorld, GameObject* pSort)
{
	PhysicsObject2D* pPhysObj;

	pPhysObj = new WoodPlatform(x - 70.0f, y, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatform(x + 70.0f, y, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x - 73.0f, y + 130.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x + 73.0f, y + 130.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x, y + 240.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x - 37.0f, y + 300.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x + 37.0f, y + 300.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatTiny(x, y + 250.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatTiny(x - 130.0f, y + 60.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatTiny(x + 130.0f, y + 60.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatTiny(x, y + 430.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x, y + 160.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x, y + 400.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatShort(x - 30.0f, y + 100.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatShort(x + 30.0f, y + 100.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new SmallPig(x, y + 280.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	GraphicsObject_Sprite* pSprite;
	PhysicsFixture fixture(Shape::Rectangle, 0.0f, 10.0f, 0.0f);
	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x + 500, y + 100, 20, 200));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	GameObjectMan::Add(pPhysObj, pSort);
}
