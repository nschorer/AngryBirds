#ifndef TIMER_EVENT_UNBLINK_H
#define TIMER_EVENT_UNBLINK_H

#include "TimerEvent.h"

class Bird_Base;

class TimerEvent_Unblink : public TimerEvent
{
private:
	Bird_Base* pBird;

public:
	TimerEvent_Unblink(Bird_Base* pBird);

	virtual void Execute(float currTime) override;


};



#endif _EventJump