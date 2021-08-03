#ifndef GLASS_CIRCLE_H
#define GLASS_CIRCLE_H


#include "Block_Base.h"

class GlassCircle : public Block_Base
{
public:

	GlassCircle(float x, float y, PhysicsWorld* pWorld);
	virtual ~GlassCircle() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif