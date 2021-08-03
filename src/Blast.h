#ifndef BLAST_H
#define BLAST_H

#include "PhysicsObject2D.h"

class Pig_Base;
class Block_Base;

class Blast : public PhysicsObject2D
{
public:

	Blast(float x, float y, PhysicsWorld* pWorld);

	virtual void CollideAccept(PhysicsObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	virtual void CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse);
	virtual void CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse);

private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
	static float width;
	static float height;


};

#endif