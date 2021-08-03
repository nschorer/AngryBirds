#include "NinjaSwordCallback.h"
#include "GameObject2D.h"
#include "NinjaFruit.h"

float32 NinjaSwordCallback::ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction)
{
	fraction;
	point;
	normal;

	// Warning: there is no smarts in this demo: we don't test whether the fixture was already added...
	// This may or may not be an issue depending your particular situation
	PhysicsObject2D* pgobj = (PhysicsObject2D*)((fixture)->GetUserData());
	if (!pgobj->IgnoresRaycast())
	{
		lstFixtures.push_front(fixture);
	}

	return 1;
}

void NinjaSwordCallback::ClearList()
{
	/*for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		GameObject2D* pgobj = (GameObject2D*)((*it)->GetUserData());
		GraphicsObject_Box* pbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		pbox->color = Color::Type::Yellow;
	}*/

	lstFixtures.clear();
}

void NinjaSwordCallback::ProcessList()
{
	for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		NinjaFruit* pgobj = (NinjaFruit*)((*it)->GetUserData());
		//GraphicsObject_Box* pbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		//pbox->color = Color::Type::Red;
		pgobj->OnCut();
	}

	ClearList();
}
