#ifndef		BIG_BIRD_H
#define		BIG_BIRD_H

#include "Bird_Base.h"

class BigBird : public Bird_Base
{
public:

	BigBird(float x, float y, PhysicsWorld* pWorld);
	virtual ~BigBird() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];
};


#endif