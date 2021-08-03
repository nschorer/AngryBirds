#ifndef SLINGSHOT_H
#define SLINGSHOT_H

#include "Sling.h"
#include "GameObject2D.h"
#include "ProjectedTrajectory.h"

class PhysicsWorld;
class BirdQueue;
class Bird_Base;


class Slingshot : public GameObject2D
{
public:

	Slingshot(float x, float y, BirdQueue* pQueue);
	~Slingshot();

	virtual void Update(float t) override;

	void LoadBirdFromQueue();
	void LoadBird(Bird_Base* pBird);
	void LaunchBird(Vect2D& impulse);

private:

	void GetDragPoint(Vect2D& slingPoint, Vect2D& birdPoint);

private:

	Sling* pSling_L;
	Sling* pSling_R;
	GameObject2D* pSling_Tree;
	GameObject2D* pSling_Branch;
	BirdQueue* pQueue;
	Bird_Base* pBird;

	ProjectedTrajectory projTraj;

	Vect2D launchDirection;
	bool shouldLaunch;
};

#endif