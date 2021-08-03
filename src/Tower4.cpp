#include "Tower4.h"
#include "PhysicsObject2D.h"
#include "GameObjectMan.h"
#include "BlocksHeader.h"
#include "WoodPlatform.h"
#include "BirdsPigsHeader.h"
#include "FerrisWheel.h"

void Tower4(float x, float y, PhysicsWorld* pWorld, GameObject* pSort)
{
	PhysicsObject2D* pPhysObj;

	FerrisWheel(x-350, y + 250, pWorld);
	
	pPhysObj = new GlassCircle(x-70, y + 40, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassCircle(x+70, y + 40, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatLong(x, y + 90, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassSquare(x - 80, y + 125, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassSquare(x + 80, y + 125, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassRect(x , y + 180, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new GlassPlatLong(x, y + 150, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	pPhysObj = new SmallPig(x, y + 20, pWorld);
	GameObjectMan::Add(pPhysObj, pSort);

	GraphicsObject_Sprite* pSprite;
	PhysicsFixture fixture(Shape::Rectangle, 0.0f, 10.0f, 0.0f);
	pSprite = new GraphicsObject_Sprite(ImageName::Name::Stone_Rect_0, Rect(x + 300, y + 100, 20, 200));
	pPhysObj = new PhysicsObject2D(GameObjectName::Name::Stone_Rect, pSprite, pWorld, BodyType::Static, &fixture);
	GameObjectMan::Add(pPhysObj, pSort);
}
