// TrailPuff
// Andre Berthiaume, May 2017

#ifndef _TrailPuff
#define _TrailPuff

#include "GameObject2D.h"

class ManagedPool;

class TrailPuff : public GameObject2D
{
private:
	ManagedPool* pPuffObjectPool;

public:
	TrailPuff() = delete;
	~TrailPuff() {};
	TrailPuff(const TrailPuff&) = delete;
	TrailPuff& operator=(const TrailPuff&) = delete;

	void SetPosAng(float pixx, float pixy, float ang);

	TrailPuff(ManagedPool* pool);

	virtual void ManagedSceneExit() override;
};

#endif _YellowBird
