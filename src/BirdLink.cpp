#include "BirdLink.h"

BirdLink::BirdLink(Bird_Base* _pBird)
	: pPrev(nullptr), pNext(nullptr), pBird(_pBird)
{
}
