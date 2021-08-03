#ifndef DEATH_ZONE_H
#define DEATH_ZONE_H

#include "PhysicsObject2D.h"

class DeathZone : public PhysicsObject2D
{
public:
	DeathZone(float x, float y, float width, float height, PhysicsWorld* pWorld);

	virtual void CollideAccept(PhysicsObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	virtual void CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse);
	//virtual void CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse);

private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
};

#endif