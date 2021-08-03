#ifndef		WHITE_BIRD_H
#define		WHITE_BIRD_H

#include "Bird_Base.h"

class WhiteBird : public Bird_Base
{
public:

	WhiteBird(float x, float y, PhysicsWorld* pWorld);
	virtual ~WhiteBird() = default;

	void Special() override;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[7];
};


#endif