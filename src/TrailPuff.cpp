#include "TrailPuff.h"
#include "Game.h"
#include "GameObjectMan.h"
#include "TrailPuffFactory.h"

TrailPuff::TrailPuff(ManagedPool* pool)
	: GameObject2D(
		GameObjectName::Puff,
		new GraphicsObject_Sprite(ImageName::Puff, Rect(0, 0, 30, 30))
	)
{
	this->currAngle = 0;
	this->SetDrawSprite(true);

	this->pBody = nullptr;	

	this->ManagedNoDelete = true;
	this->pPuffObjectPool = pool;
}

void TrailPuff::SetPosAng(float pixx, float pixy, float ang)
{
	this->posX = pixx;
	this->posY = pixy;
	this->origAngle = ang;
}

void TrailPuff::ManagedSceneExit()
{
	pPuffObjectPool->Recycle(this);
}