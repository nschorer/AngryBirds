#ifndef		GREEN_BIRD_H
#define		GREEN_BIRD_H

#include "Bird_Base.h"

class GreenBird : public Bird_Base
{
public:

	GreenBird(float x, float y, PhysicsWorld* pWorld);
	virtual ~GreenBird() = default;

	virtual void Update(float t) override;

	void Special() override;

	void OnCollide() override;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[5];

	bool boomerangOn;
};


#endif