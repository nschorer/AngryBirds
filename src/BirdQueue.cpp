#include "BirdQueue.h"

#include "PhysicsMan.h"
#include "GameObjectMan.h"
#include "AngryCamera.h"

BirdQueue::BirdQueue(int _capacity, float _qFrontX, float _qFrontY, PhysicsWorld* _pWorld)
	:pHead(nullptr), pWorld(_pWorld), capacity(_capacity), size(0), qFrontX(_qFrontX), qFrontY(_qFrontY)
{
}

BirdQueue::~BirdQueue()
{
	// Delete the LINKs, the GOManager will clean up the birds themselves
	BirdLink* pLink = pHead;
	while (pLink != nullptr)
	{
		BirdLink* pDelete = pLink;
		pLink = pLink->pNext;
		delete pDelete;
	}
}

void BirdQueue::Reload(Type type)
{
	for (int i = this->size; i < this->capacity; ++i)
	{
		Bird_Base* pBird = nullptr;
		switch (type)
		{
		case Type::RED:
			pBird = new RedBird(0, 0, pWorld);
			break;
		case Type::YELLOW:
			pBird = new YellowBird(0, 0, pWorld);
			break;
		case Type::GREEN:
			pBird = new GreenBird(0, 0, pWorld);
			break;
		case Type::BLUE:
			pBird = new BlueBird(0, 0, pWorld);
			break;
		case Type::WHITE:
			pBird = new WhiteBird(0, 0, pWorld);
			break;
		case Type::BLACK:
			pBird = new BlackBird(0, 0, pWorld);
			break;
		case Type::BIG:
			pBird = new BigBird(0, 0, pWorld);
			break;
		}

		GameObjectMan::Add(pBird, GameObjectName::MainGroup);
		Push(pBird);
		pBird->WaitInLine();
	}
	AngryCamera::SetMode(AngryCamera::Mode::Waiting);
}

void BirdQueue::Push(Bird_Base* pBird)
{
	assert(pBird);
	float spacing = 100.0f;

	if (this->size == 0)
	{
		assert(pHead == nullptr);
		pHead = new BirdLink(pBird);
	}
	else
	{
		assert(pHead != nullptr);
		BirdLink* pTmp = pHead;

		for (int i = 1; i < this->size; ++i)
		{
			pTmp = pTmp->pNext;
		}

		pTmp->pNext = new BirdLink(pBird);
		pTmp->pNext->pPrev = pTmp;
	}

	pBird->SetPosition(qFrontX - (this->size * spacing), qFrontY);
	pBird->SetPhysicsActive(false);

	this->size++;
}

Bird_Base* BirdQueue::Pop()
{
	assert(this->size > 0);
	Bird_Base* pBird = pHead->pBird;
	BirdLink* pOld = pHead;

	pHead = pHead->pNext;
	pHead->pPrev = nullptr;
	delete pOld; // delete the link, leave the bird
	this->size--;

	AdvanceQueue();

	return pBird;
}

void BirdQueue::AdvanceQueue()
{
	BirdLink* pTmp = pHead;
	float spacing = 100.0f;

	float x = this->qFrontX;

	while (pTmp != nullptr)
	{
		pTmp->pBird->SetPosition(x, qFrontY);
		pTmp = pTmp->pNext;
		x -= spacing;
	}
}
