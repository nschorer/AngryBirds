#include "ContactAction.h"
//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "BlocksHeader.h"
#include "BirdsPigsHeader.h"
#include "Blast.h"
#include "Game.h"
#include "PixelToMeter.h"
#include "GameObjectMan.h"
#include "PhysicsObject2D.h"
#include "DeathZone.h"

void ContactAction::ContactPair(Bird_Base& bird, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	bird.OnCollide();

	bool doubleDmg = (bird.Get2xMask() & block.GetMaterialBit()) > 0;
	bool destroy = (bird.GetDestroyMask() & block.GetMaterialBit()) > 0;

	if (pImpulse) {

		for (int i = 0; i < pImpulse->count; i++)
		{
			// Record Damage
			float damage = pImpulse->normalImpulses[i];
			damage *= 2;
			if (doubleDmg)
			{
				damage *= 2;
			}

			block.DoDamage(damage);
		}
	}
	// punch through!
	else if (destroy)
	{
		//b2Body* pB2Body = bird.GetPhysicsBody()->GetB2Body();
		//b2Vec2 vel = pB2Body->GetLinearVelocity();
		block.DoDamage(10000);
		pContact->SetEnabled(false);
		//pB2Body->ApplyLinearImpulse(.5f * pB2Body->GetMass() * (-vel), pB2Body->GetWorldCenter(), true);
	}
}

void ContactAction::ContactPair(Bird_Base& bird, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	bird.OnCollide();
	pig.DestroyJoint();
	for (int i = 0; i < pImpulse->count; i++)
	{
		// Record Damage
		float damage = pImpulse->normalImpulses[i];
		damage *= 2;
		pig.DoDamage(damage);
	}
}

void ContactAction::ContactPair(Bird_Base& bird, Floor& floor, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird.OnCollide();
	floor;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(Pig_Base& pig, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	for (int i = 0; i < pImpulse->count; i++)
	{
		if (pImpulse->normalImpulses[i] > 20.0f)
		{
			// Record Damage
			pig.DoDamage(pImpulse->normalImpulses[i]);
			block.DoDamage(pImpulse->normalImpulses[i]);
		}
	}
}

void ContactAction::ContactPair(WhiteBirdEgg& egg, Block_Base& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	obj;
	pContact;
	pImpulse;
	egg.Break();
}

void ContactAction::ContactPair(WhiteBirdEgg& egg, Pig_Base& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	obj;
	pContact;
	pImpulse;
	egg.Break();
}

void ContactAction::ContactPair(WhiteBirdEgg& egg, Floor& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	obj;
	pContact;
	pImpulse;
	egg.Break();
}

void ContactAction::ContactPair(Blast& blast, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{

	float damage = 10.0f;
		// Record Damage
		block.DoDamage(damage);


	ApplyRadialImpulse(blast, block, pContact, pImpulse);
}

void ContactAction::ContactPair(Blast& blast, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float damage = 10.0f;
	// Record Damage
	pig.DoDamage(damage);


	ApplyRadialImpulse(blast, pig, pContact, pImpulse);
}

void ContactAction::ContactPair(DeathZone& zone, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	zone;
	pContact;
	pImpulse;
	pig.DoDamage(10000);
}

void ContactAction::ContactPair(Pig_Base& pig1, Pig_Base& pig2, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	for (int i = 0; i < pImpulse->count; i++)
	{
		// Record Damage
		pig1.DoDamage(pImpulse->normalImpulses[i]);
		pig2.DoDamage(pImpulse->normalImpulses[i]);
	}
}

void ContactAction::ContactPair(Block_Base& block1, Block_Base& block2, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	for (int i = 0; i < pImpulse->count; i++)
	{
		if (pImpulse->normalImpulses[i] > 50)
		{
			// Record Damage
			block1.DoDamage(pImpulse->normalImpulses[i]);
			block2.DoDamage(pImpulse->normalImpulses[i]);
		}
	}
}

void ContactAction::ContactPair(Bird_Base& bird1, Bird_Base& bird2, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird1.OnCollide();
	bird2.OnCollide();
	pContact;
	pImpulse;
}


void ContactAction::ApplyRadialImpulse(Blast& blast, PhysicsObject2D& obj, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	pImpulse;

	Vect v(obj.posX - blast.posX, obj.posY - blast.posY, 0.0f);
	float fStrength = 20.0f;
	v = v.getNorm() * fStrength;

	Vect2D force(v.X(), v.Y());
	obj.ApplyImpulse(force);

}
