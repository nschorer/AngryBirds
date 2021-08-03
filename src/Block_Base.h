#ifndef BLOCK_BASE_H
#define BLOCK_BASE_H

#include "PhysicsObject2D.h"
#include "PhysicsMaterial.h"

class Pig_Base;
class Blast;

class Block_Base : public PhysicsObject2D
{
public:

	virtual ~Block_Base() = default;

	virtual void CollideAccept(PhysicsObject2D & other, b2Contact * contact, const b2ContactImpulse * pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Bird_Base& other, b2Contact * pcontact, const b2ContactImpulse * pimpulse) override;
	virtual void CollideVisit(WhiteBirdEgg& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Blast& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;

	void DoDamage(float damage);
	int GetMaterialBit();
	void SetInvincible(bool invincible);

protected:
	Block_Base(GameObjectName::Name name, float x, float y, float width, float height, PhysicsFixture* Fixture, ImageName::Name imgNames[4], PhysicsMaterial* pMaterial, PhysicsWorld* pWorld);
	Block_Base() = delete;

private:

	void Die();

protected:

	PhysicsMaterial* const pMaterial;
	ImageName::Name* imgNames;
	float health;
	bool invincible;

	static const int numImgs = 4;
};

#endif