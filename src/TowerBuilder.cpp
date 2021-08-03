#include "TowerBuilder.h"

#include "TimerEvent_BuildTower.h"
#include "TimerMan.h"
#include "GameObjectMan.h"
#include "PhysicsMan.h"


#include "PigTracker.h"
#include "Tower1.h"
#include "Tower2.h"
#include "Tower3.h"
#include "Tower4.h"
#include "Tower5.h"

void CleanupTower()
{
	GameObject2D* pObj;
	GameObject2D* pObjNext;

	PigTracker::SetTracker(false);

	GameObject* pSort = GameObjectMan::Find(GameObjectName::Name::TowerGroup);
	pObj = (GameObject2D*)pSort->getChild();

	while (pObj != nullptr)
	{
		pObjNext = (GameObject2D*)pObj->getSibling();

		pObj->MarkForDelete();

		pObj = pObjNext;
	}

	pSort = GameObjectMan::Find(GameObjectName::Name::TowerBackground);
	pObj = (GameObject2D*)pSort->getChild();

	while (pObj != nullptr)
	{
		pObjNext = (GameObject2D*)pObj->getSibling();

		pObj->MarkForDelete();

		pObj = pObjNext;
	}
}

void BuildTower_Queue(Tower tower)
{
	CleanupTower();

	TimerEvent_BuildTower* pEvent = new TimerEvent_BuildTower(tower);
	TimerMan::AddEvent(0.1f, pEvent);
}

void BuildTower_Construct(Tower tower)
{
	GameObject* pSort = GameObjectMan::Find(GameObjectName::Name::TowerGroup);
	PhysicsWorld* pWorld = PhysicsMan::GetWorld();

	float x = 1400.0f;
	float y = 0.0f;

	PigTracker::SetPigCount(0);
	PigTracker::SetTracker(true);

	switch (tower)
	{
	case Tower::ONE:
		Tower1(x-200, y, pWorld, pSort);
		break;
	case Tower::TWO:
		Tower2(x-300, y, pWorld, pSort);
		break;
	case Tower::THREE:
		Tower3(x, y, pWorld, pSort);
		break;
	case Tower::FOUR:
		Tower4(x, y, pWorld, pSort);
		break;
	case Tower::FIVE:
		Tower5(x, y, pWorld, pSort);
		break;
	default:
		assert(false && "Case not implemented");
		break;
	}
}
