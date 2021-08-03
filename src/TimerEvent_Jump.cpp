#include "TimerEvent_Jump.h"
#include "TimerMan.h"
#include "Bird_Base.h"

TimerEvent_Jump::TimerEvent_Jump(Bird_Base* _pBird)
{
	this->pBird = _pBird;
}

void TimerEvent_Jump::Execute(float currTime)
{
	currTime;
	pBird->Jump();
}