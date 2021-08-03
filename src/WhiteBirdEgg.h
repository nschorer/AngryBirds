#ifndef WHITE_BIRD_EGG_H
#define WHITE_BIRD_EGG_H

#include "PhysicsObject2D.h"

class WhiteBirdEgg : public PhysicsObject2D
{
public:
	~WhiteBirdEgg() = default;
	WhiteBirdEgg(const WhiteBirdEgg&) = delete;
	WhiteBirdEgg& operator=(const WhiteBirdEgg&) = delete;

	WhiteBirdEgg(float x, float y, PhysicsWorld* pWorld);

	virtual void CollideAccept(PhysicsObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	
	virtual void CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Floor& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;

	void Break();

private:

	WhiteBirdEgg() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgName;
};

#endif