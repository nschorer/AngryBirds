#include "TimerEvent_BuildTower.h"
#include "TowerBuilder.h"

TimerEvent_BuildTower::TimerEvent_BuildTower(Tower _tower)
	:tower(_tower)
{
}

void TimerEvent_BuildTower::Execute(float currTime)
{
	currTime;
	BuildTower_Construct(tower);
}
