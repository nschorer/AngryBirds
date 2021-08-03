#ifndef TIMER_EVENT_BLINK_H
#define TIMER_EVENT_BLINK_H

#include "TimerEvent.h"

class Bird_Base;

class TimerEvent_Blink : public TimerEvent
{
private:
	Bird_Base* pBird;

public:
	TimerEvent_Blink(Bird_Base* pBird);

	virtual void Execute(float currTime) override;


};



#endif TIMER_EVENT_BLINK_H