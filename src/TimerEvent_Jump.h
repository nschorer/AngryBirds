// JumpTimerCmd
// AB 4/18
// 
#ifndef _EventJump
#define _EventJump

#include "TimerEvent.h"

class Bird_Base;

class TimerEvent_Jump : public TimerEvent
{
private:
	Bird_Base* pBird;

public:
	TimerEvent_Jump(Bird_Base* pBird);

	virtual void Execute(float currTime) override;


};



#endif _EventJump