#ifndef NINJA_LAUNCHER_H
#define NINJA_LAUNCHER_H

class PhysicsWorld;

class NinjaLauncher
{
public:
	NinjaLauncher(float x, float y, float radius, PhysicsWorld* pWorld);

	void StartLaunching();

private:
	void LaunchRandomFruit();

	float x;
	float y;
	float radius;
	PhysicsWorld* pWorld;
};

#endif