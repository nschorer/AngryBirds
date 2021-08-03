#ifndef BLACK_BIRD_H
#define BLACK_BIRD_H

#include "Bird_Base.h"

class BlackBird : public Bird_Base
{
public:

	BlackBird(float x, float y, PhysicsWorld* pWorld);
	virtual ~BlackBird() = default;

	virtual void Update(float t) override;

	virtual void Special() override;
	void Explode();

	virtual void OnCollide() override;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[7];

	int bombCount;
};


#endif