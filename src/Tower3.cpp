#include "Tower3.h"
#include "PhysicsObject2D.h"
#include "GameObjectMan.h"
#include "BlocksHeader.h"
#include "WoodPlatform.h"
#include "BirdsPigsHeader.h"

void Tower3(float x, float y, PhysicsWorld* pWorld, GameObject* pSort)
{
	PhysicsObject2D* pPhysObj;

	pPhysObj = new WoodPlatShort(x - 400, y + 50.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StonePlatShort(x - 400, y + 100.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new SmallPig(x - 400, y + 135, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x-280, y + 50.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x - 240, y + 50.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x - 200, y + 50.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x - 160, y + 50.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x - 200, y + 100.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new SmallPig(x - 200, y + 135, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StonePlatShort(x-280, y + 187.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new MediumPig(x-280, y + 230.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatLong(x-120 , y + 50.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StonePlatShort(x -120, y + 220.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);
	
	pPhysObj = new BigPig(x -120, y + 280.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatLong(x - 450, y + 100, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);
	pPhysObj->SetAngle(MATH_PI2);

	pPhysObj = new StonePlatMedium(x - 450, y + 220, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	GraphicsObject_Sprite* pSprite;
	PhysicsFixture fixture(Shape::Rectangle, 0.0f, 10.0f, 0.0f);
	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x + 300, y + 100, 20, 200));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	GameObjectMan::Add(pPhysObj, pSort);
}
