#ifndef STONE_CIRCLE_H
#define STONE_CIRCLE_H


#include "Block_Base.h"

class StoneCircle : public Block_Base
{
public:

	StoneCircle(float x, float y, PhysicsWorld* pWorld);
	virtual ~StoneCircle() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif