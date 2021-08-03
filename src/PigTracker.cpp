#include "PigTracker.h"
#include "AudioManager.h"

bool PigTracker::trackerOn(false);
int PigTracker::pigCount(0);

void PigTracker::SetPigCount(int count)
{
	trackerOn = true;
	pigCount = count;
}

void PigTracker::PigBorn()
{
	if (trackerOn)
	{
		pigCount++;
	}
}

void PigTracker::PigKilled()
{
	if (trackerOn) {
		pigCount--;
		
		//Trace::out("%i\n", pigCount);

		// With more time and a better design, these should be decoupled
		if (pigCount <= 0)
		{
			if (pigCount < 0)
			{
				Trace::out("\nPig count is less than 0...\n");
			}
			AudioManager::LevelClear();
		}
	}
}

void PigTracker::SetTracker(bool on)
{
	trackerOn = on;
}

int PigTracker::PigCount()
{
	if (trackerOn)
	{
		return pigCount;
	}
	// Don't use when tracker is off
	return -1;
}
