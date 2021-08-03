#ifndef		YELLOW_BIRD_H
#define		YELLOW_BIRD_H

#include "Bird_Base.h"

class YellowBird : public Bird_Base
{
public:

	YellowBird(float x, float y, PhysicsWorld* pWorld);
	virtual ~YellowBird() = default;

	virtual void Update(float t) override;

	void Special() override;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[5];

	int zoomCount;
};


#endif