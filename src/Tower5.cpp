#include "Tower5.h"
#include "PhysicsObject2D.h"
#include "GameObjectMan.h"
#include "BlocksHeader.h"
#include "WoodPlatform.h"
#include "BirdsPigsHeader.h"

void Tower5(float x, float y, PhysicsWorld* pWorld, GameObject* pSort)
{
	PhysicsObject2D* pPhysObj;
	GraphicsObject_Sprite* pSprite;
	
	PhysicsFixture fixture(Shape::Rectangle, 0.0f, 10.0f, 0.0f);

	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x - 400, y + 100, 150, 200));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	GameObjectMan::Add(pPhysObj, pSort);

	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x - 300, y + 70, 250, 100));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	pPhysObj->SetAngle(-MATH_PI4);
	GameObjectMan::Add(pPhysObj, pSort);

	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x - 50, y + 180, 250, 100));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	GameObjectMan::Add(pPhysObj, pSort);

	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x+100, y + 120, 250, 100));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	pPhysObj->SetAngle(-MATH_PI4);
	GameObjectMan::Add(pPhysObj, pSort);


	pPhysObj = new StoneSquare(x - 50, y + 230, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x - 100, y + 230, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);
	
	pPhysObj = new StoneSquare(x - 125, y + 280, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x - 65, y + 280, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StonePlatTiny(x - 450, y + 210, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneCircle(x - 390, y + 250.0f, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new MediumPig(x-50, y+20, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new StoneRect(x-600, y+20, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);
	pPhysObj = new StoneRect(x - 600, y+60, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);
	pPhysObj = new StoneRect(x - 600, y+125, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatMedium(x - 550, y + 100, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new SmallPig(x - 525, y, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

}
