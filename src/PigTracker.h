#ifndef PIG_TRACKER_H
#define PIG_TRACKER_H

class PigTracker
{
public:

	static void SetPigCount(int count);
	static void PigBorn();
	static void PigKilled();
	static void SetTracker(bool on);

	// Debug
	static int PigCount();

private:
	PigTracker() = default;

	static bool trackerOn;
	static int pigCount;
};

#endif