#ifndef FLOOR_H
#define FLOOR_H

#include "PhysicsObject2D.h"

class Floor : public PhysicsObject2D
{
public:
	Floor(float x, float y, float width, float height, PhysicsWorld* pWorld);

	virtual void CollideAccept(PhysicsObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void CollideVisit(Bird_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(WhiteBirdEgg& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;

private:
	static PhysicsFixture fixture;
};

#endif