#ifndef GLASS_MATERIAL_H
#define GLASS_MATERIAL_H

#include "PhysicsMaterial.h"

class GlassMaterial : public PhysicsMaterial
{
public:
	GlassMaterial() = default;
	virtual ~GlassMaterial() = default;

	const float Density() final { return 5.0f; }
	const float Friction() final { return 0.1f; }
	const float Restitution() final { return 0.3f; }
	const float Health() final { return 200.0f; }
	const MaterialMask MaterialBit() final { return MaterialMask::GLASS; }

	static GlassMaterial* Instance();
};

#endif