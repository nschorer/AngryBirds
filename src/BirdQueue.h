#ifndef BIRD_QUEUE_H
#define BIRD_QUEUE_H

#include "BirdsPigsHeader.h"
#include "BirdLink.h"

class PhysicsWorld;

class BirdQueue
{
public:

	enum class Type
	{
		RED,
		YELLOW,
		BLUE,
		GREEN,
		WHITE,
		BLACK,
		BIG
	};

	BirdQueue(int capacity, float qFrontX, float qFrontY, PhysicsWorld* pWorld);
	~BirdQueue();

	void Reload(Type type = Type::RED);
	void Push(Bird_Base* pBird);
	Bird_Base* Pop();

private:

	void AdvanceQueue();

private:
	BirdLink* pHead;
	PhysicsWorld* pWorld;

	int capacity;
	int size;
	float qFrontX;
	float qFrontY;

};

#endif