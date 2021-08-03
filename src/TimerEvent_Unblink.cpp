#include "TimerEvent_Unblink.h"
#include "Bird_Base.h"

TimerEvent_Unblink::TimerEvent_Unblink(Bird_Base* _pBird)
	:pBird(_pBird)
{
}

void TimerEvent_Unblink::Execute(float currTime)
{
	currTime;
	pBird->Unblink();
}
