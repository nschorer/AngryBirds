// ContactAction

#ifndef _ContactAction
#define _ContactAction

struct b2ContactImpulse;
class b2Contact;

class Block_Base;
class Pig_Base;
class Bird_Base;

class WhiteBirdEgg;
class Blast;
class Floor;

class DeathZone;
class PhysicsObject2D;

class ContactAction
{
public:

	static void ContactPair(Bird_Base& bird, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Bird_Base& bird, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Bird_Base& bird, Floor& floor, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Pig_Base& pig, Block_Base& block1, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(WhiteBirdEgg& egg, Block_Base& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBirdEgg& egg, Pig_Base& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBirdEgg& egg, Floor& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Blast& blast, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& blast, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(DeathZone& zone, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	// Stop hitting yourself
	static void ContactPair(Pig_Base& pig1, Pig_Base& pig2, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Block_Base& block1, Block_Base& block2, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Bird_Base& block1, Bird_Base& block2, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ApplyRadialImpulse(Blast& blast, PhysicsObject2D& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse);

};

#endif _ContactAction
