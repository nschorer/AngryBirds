#ifndef TIMER_EVENT_BLAST_H
#define TIMER_EVENT_BLAST_H

#include "TimerEvent.h"
#include "GameObject2D.h"

class TimerEvent_Blast : public TimerEvent
{
public:
	TimerEvent_Blast(float x, float y);
	virtual ~TimerEvent_Blast() = default;

	virtual void Execute(float currTime) override;

	float x;
	float y;
};

#endif