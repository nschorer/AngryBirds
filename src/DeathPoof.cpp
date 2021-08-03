#include "DeathPoof.h"
#include "TimerMan.h"
#include "TimerEvent_DeleteGameObject.h"

DeathPoof::DeathPoof(GameObject2D& gObj)
	:GameObject2D(GameObjectName::Name::Puff, new GraphicsObject_Sprite(ImageName::Name::Puff, Rect(gObj.posX, gObj.posY, (gObj.origWidth + gObj.origHeight)/2, (gObj.origWidth + gObj.origHeight) / 2)))
{
	TimerMan::AddEvent(0.5f, new TimerEvent_DeleteGameObject(this));
}
