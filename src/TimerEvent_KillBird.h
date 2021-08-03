#ifndef TIMER_EVENT_KILL_BIRD_OBJECT_H
#define TIMER_EVENT_KILL_BIRD_OBJECT_H

#include "TimerEvent.h"
#include "GameObject2D.h"

class Bird_Base;

class TimerEvent_KillBird : public TimerEvent
{
public:
	TimerEvent_KillBird(Bird_Base* pBird);
	virtual ~TimerEvent_KillBird() = default;

	virtual void Execute(float currTime) override;

	Bird_Base* pBird;
};

#endif