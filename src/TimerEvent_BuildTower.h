#ifndef TIMER_EVENT_BUILD_TOWER_H
#define TIMER_EVENT_BUILD_TOWER_H

#include "TimerEvent.h"

enum class Tower;

class TimerEvent_BuildTower : public TimerEvent
{
private:
	Tower tower;

public:
	TimerEvent_BuildTower(Tower _tower);

	virtual void Execute(float currTime) override;


};


#endif