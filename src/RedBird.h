#ifndef RED_BIRD_H
#define RED_BIRD_H

#include "Bird_Base.h"

class RedBird : public Bird_Base
{
public:

	RedBird(float x, float y, PhysicsWorld* pWorld);
	virtual ~RedBird() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];
};


#endif
