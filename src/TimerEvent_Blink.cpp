#include "TimerEvent_Blink.h"
#include "Bird_Base.h"

TimerEvent_Blink::TimerEvent_Blink(Bird_Base* _pBird)
	:pBird(_pBird)
{
}

void TimerEvent_Blink::Execute(float currTime)
{
	currTime;
	pBird->Blink();
}
