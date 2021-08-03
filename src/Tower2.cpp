#include "Tower2.h"
#include "PhysicsObject2D.h"
#include "GameObjectMan.h"
#include "BlocksHeader.h"
#include "WoodPlatform.h"
#include "BirdsPigsHeader.h"

void Tower2(float x, float y, PhysicsWorld* pWorld, GameObject* pSort)
{
	PhysicsObject2D* pPhysObj;

	pPhysObj = new StoneRect(x - 120, 30.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x + 120, 30.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x - 170, 30.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x + 170, 30.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new MediumPig(x, y + 100.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodSquare(x - 100, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x - 160, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x + 125, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodSquare(x + 185, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x - 125, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodSquare(x - 175, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x + 164, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodSquare(x + 105, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x - 140, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x + 145.0f, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x + 95.0f, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x + 195.0f, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x - 90, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatShort(x - 190, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x - 140, y + 220.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x - 203, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x - 77, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x - 140, y + 310.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new SmallPig(x - 140, y + 230.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassRect(x - 140, y + 325.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatShort(x - 140, y + 380.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x + 145, y + 220.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x + 82, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodRect(x + 208, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new WoodPlatMedium(x + 145, y + 310.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new SmallPig(x + 145.0f, y + 230.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassRect(x + 145.0f, y + 325.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatShort(x + 145.0f, y + 380.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, pSort);

	GraphicsObject_Sprite* pSprite;
	PhysicsFixture fixture(Shape::Rectangle, 0.0f, 10.0f, 0.0f);
	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x + 600, y + 100, 20, 200));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	GameObjectMan::Add(pPhysObj, pSort);
}
