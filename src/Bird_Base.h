#ifndef BIRD_BASE_H
#define BIRD_BASE_H

#include "PhysicsObject2D.h"
#include "AwakeListenerBase.h"

class Bird_Base : public PhysicsObject2D, public AwakeListenerBase
{

public:

	enum class State
	{
		FREE,
		IN_LINE,
		IN_SLING,
		LAUNCHED,
		COLLIDED
	};

	enum class IMG_INDEX
	{
		NORMAL = 0,
		BLINK,
		FLYING,
		DAMAGED,
	};

	enum class EyeState
	{
		WAITING,
		OPEN,
		CLOSE
	};

public:

	virtual ~Bird_Base() = default;

	virtual void CollideAccept(PhysicsObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Floor& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Bird_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;

	virtual void Update(float t) override;

	virtual void Special();
	virtual void Jump();
	virtual void Blink();
	virtual void Unblink();
	virtual void Die();

	virtual void WaitInLine();
	virtual void LoadIntoSling();
	virtual void Launch();
	virtual void OnCollide();

	void ManageBlinkState();
	void BirdPoint();
	void GenerateSmokeTrail(float t);
	void CheckForSpecial();

	virtual byte Get2xMask();
	virtual byte GetDestroyMask();

	/// Called when body is first awaken
	virtual void BeginAwake(b2Body* _body) override;

	/// Called when body is first set to sleep
	virtual void EndAwake(b2Body* _body) override;

	void static RecallSmokeTrail();
	void static CleanupBirds();

protected:
	Bird_Base(GameObjectName::Name name, float x, float y, float width, float height, PhysicsFixture* Fixture, ImageName::Name imgNames[4], PhysicsWorld* pWorld);
	Bird_Base() = delete;

protected:

	ImageName::Name* imgNames;
	bool usedSpecial;
	State birdState;
	bool triggerJump;
	EyeState eyeState;
	byte mask_2xMaterial;
	byte mask_destroyMaterial;

	static const int numImgs = 4;



};

#endif