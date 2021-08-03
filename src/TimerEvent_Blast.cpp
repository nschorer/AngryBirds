#include "TimerEvent_Blast.h"
#include "Blast.h"
#include "GameObjectMan.h"

TimerEvent_Blast::TimerEvent_Blast(float _x, float _y)
	:x(_x), y(_y)
{
}

void TimerEvent_Blast::Execute(float currTime)
{
	currTime;
	GameObject* pObj = new Blast(x, y, PhysicsMan::GetWorld());
	GameObjectMan::Add(pObj, GameObjectName::Name::Effects);
}
