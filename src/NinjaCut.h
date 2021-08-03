#ifndef NINJA_CUT_H
#define NINJA_CUT_H

#include "GameObject2D.h"

class NinjaSwordCallback;

class NinjaCut : public GameObject2D
{
public:
	NinjaCut(NinjaSwordCallback* pRCCB, Vect& start, Vect& end, float len);
	virtual ~NinjaCut() = default;
};

#endif