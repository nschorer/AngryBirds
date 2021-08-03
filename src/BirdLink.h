#ifndef BIRD_LINK_H
#define BIRD_LINK_H

#include "BirdsPigsHeader.h"

class BirdLink
{
public:
	BirdLink(Bird_Base* pBird);

	BirdLink* pPrev;
	BirdLink* pNext;
	Bird_Base* pBird;
};

#endif