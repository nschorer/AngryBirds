#include "ProjectedTrajectory.h"
#include "Game.h"
#include "PixelToMeter.h"
#include "PhysicsMan.h"

void ProjectedTrajectory::Trace(b2Vec2 initPos, b2Vec2 initVel, int count)
{
	pTrailFact.RecallTrail();  // Recall the previous projected trail

	float timestep = 1.0f / 60;
	b2Vec2 a = PhysicsMan::GetWorld()->GetWorld()->GetGravity();

	b2Vec2 p = initPos;
	float t;
	for (int i = 0; i < count; i++)
	{
		t = 5 * i * timestep;
		p = initPos + t * initVel + t * t * 0.5f * a;

		pTrailFact.Create(MeterToPixel(p.x), MeterToPixel(p.y), 0, .4f);
	}
}

void ProjectedTrajectory::ClearTrail()
{
	pTrailFact.RecallTrail();  // Recall the previous projected trail
}
