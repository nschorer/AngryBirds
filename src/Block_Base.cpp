#include "Block_Base.h"
#include "ContactAction.h"
#include "AudioManager.h"
#include "DeathPoof.h"
#include "GameObjectMan.h"
#include "TimerMan.h"
#include "TimerEvent_DeleteGameObject.h"

Block_Base::Block_Base(GameObjectName::Name name, float x, float y, float width, float height, PhysicsFixture* pFixture, ImageName::Name _imgNames[4], PhysicsMaterial* _pMaterial, PhysicsWorld* pWorld)
	:PhysicsObject2D(name, new GraphicsObject_Sprite(_imgNames[0], Rect(x, y, width, height)), pWorld, BodyType::Dynamic, pFixture), 
		pMaterial(_pMaterial), imgNames(_imgNames), health(_pMaterial->Health()), invincible(false)
{
}

void Block_Base::CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::CollideVisit(Bird_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	//if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::CollideVisit(WhiteBirdEgg& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::CollideVisit(Blast& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	//if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::DoDamage(float damage)
{
	if (!invincible) {
		float maxHealth = pMaterial->Health();
		health -= damage;

		GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();

		if (health > maxHealth * 0.75f)
		{
			pSprite->SetImage(this->imgNames[0]);
		}
		else if (health > maxHealth * 0.5f)
		{
			pSprite->SetImage(this->imgNames[1]);
		}
		else if (health > maxHealth * 0.25f)
		{
			pSprite->SetImage(this->imgNames[2]);
		}
		else if (health > 0)
		{
			pSprite->SetImage(this->imgNames[3]);
		}
		else {
			Die();
		}
	}
}

int Block_Base::GetMaterialBit()
{
	return (int)pMaterial->MaterialBit();
}

void Block_Base::SetInvincible(bool _invincible)
{
	invincible = _invincible;
}



void Block_Base::Die()
{
	//this->MarkForDelete();
	TimerMan::AddEvent(0.0f, new TimerEvent_DeleteGameObject(this));
	GameObjectMan::Add(new DeathPoof(*this), GameObjectName::Name::Effects);

	switch (pMaterial->MaterialBit())
	{
	case MaterialMask::GLASS:
		AudioManager::GlassNoise();
		break;
	case MaterialMask::WOOD:
		AudioManager::WoodNoise();
		break;
	case MaterialMask::STONE:
		AudioManager::StoneNoise();
		break;
	}
}
