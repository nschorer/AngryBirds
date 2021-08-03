#ifndef		BLUE_BIRD_H
#define		BLUE_BIRD_H

#include "Bird_Base.h"

class BlueBird : public Bird_Base
{
public:

	BlueBird(float x, float y, PhysicsWorld* pWorld, bool isClone = false);
	virtual ~BlueBird() = default;

	void Special() override;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];
};


#endif