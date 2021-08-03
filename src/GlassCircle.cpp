#include "GlassCircle.h"
#include "GlassMaterial.h"

PhysicsFixture GlassCircle::fixture(Shape::Circle, *GlassMaterial::Instance());
float GlassCircle::width = 76.0f;
float GlassCircle::height = 76.0f;
ImageName::Name GlassCircle::imgNames[] = { ImageName::Name::Glass_Circle_0, ImageName::Name::Glass_Circle_1, ImageName::Name::Glass_Circle_2, ImageName::Name::Glass_Circle_3 };

GlassCircle::GlassCircle(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Glass_Circle, x, y, width, height, &fixture, imgNames, GlassMaterial::Instance(), pWorld)
{

}
