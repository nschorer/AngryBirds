#include "TimerEvent_KillBird.h"
#include "GameObjectMan.h"
#include "Bird_Base.h"

TimerEvent_KillBird::TimerEvent_KillBird(Bird_Base* _pBird)
	:pBird(_pBird)
{
}

void TimerEvent_KillBird::Execute(float currTime)
{
	currTime;
	pBird->Die();
}
