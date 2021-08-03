#include "TimerEvent_LaunchFruit.h"

TimerEvent_LaunchFruit::TimerEvent_LaunchFruit(NinjaLauncher* _pLauncher)
	:pLauncher(_pLauncher)
{
}

void TimerEvent_LaunchFruit::Execute(float currTime)
{
	currTime;
	pLauncher->StartLaunching();
}
