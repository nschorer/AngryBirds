#include "AngryCamera.h"
#include "Camera.h"
#include "Bird_Base.h"

void AngryCamera::Init(float x, float y, float zoom)
{
	Instance()->xShift = x;
	Instance()->yShift = y;
	Instance()->zoomFactor = zoom;
}

void AngryCamera::Frame(Camera* pCam)
{
	AngryCamera* pAngry = Instance();
	assert(pAngry);

	float target_zoomFactor = 1.5f;
	float target_xShift = 0.0f;
	float target_yShift = 0.0f;

	float& zf = Instance()->zoomFactor;
	float& xs = Instance()->xShift;
	float& ys = Instance()->yShift;

	switch (pAngry->mode)
	{
		case Mode::Waiting:
		{
			target_zoomFactor = 1.0f;
			target_xShift = -200.0f;
			target_yShift = -50.0f;
			break;
		}
		case Mode::Sling_Pulled:
		{
			target_zoomFactor = 1.8f;
			target_xShift = 200.0f;
			target_yShift = 0.0f;
			break;
		}
		case Mode::Flying:
		{
			target_zoomFactor = 1.0f;
			target_xShift = pAngry->pBird->posX/2;
			target_yShift = -50.0f;

			if (target_xShift > 1000.0f)
			{
				target_xShift = 800.0f;
			}

			break;
		}
		case Mode::Collided:
		{
			target_zoomFactor = 1.3f;
			target_xShift = 800.0f;
			target_yShift = 0.0f;
			break;
		}

		case Mode::Free:
		{
			target_zoomFactor = zf;
			target_xShift = xs;
			target_yShift = ys;
		}
	}



	if (zf != target_zoomFactor)
	{
		float margin = 0.05f;
		float diff = zf - target_zoomFactor;
		if (diff < 0.0f) {
			diff *= -1;
		}
		if ( diff < margin)
		{
			zf = target_zoomFactor;
		}
		else
		{
			if (zf - target_zoomFactor > 0)
			{
				zf -= 0.02f;
			}
			else
			{
				zf += 0.02f;
			}
		}
	}

	if (xs != target_xShift)
	{
		float margin = 10.0f;
		float diff = xs - target_xShift;
		if (diff < 0.0f)
		{
			diff *= -1;
		}
		if ( diff < margin)
		{
			xs = target_xShift;
		}
		else
		{
			if (xs - target_xShift > 0)
			{
				xs -= 9.0f;
			}
			else
			{
				xs += 9.0f;
			}
		}
	}

	if (ys != target_yShift)
	{
		float margin = 5.0f;
		float diff = ys - target_yShift;
		if (diff < 0.0f)
		{
			diff *= -1;
		}
		if ( diff < margin)
		{
			ys = target_yShift;
		}
		else
		{
			if (ys - target_yShift > 0)
			{
				ys -= 2.0f;
			}
			else
			{
				ys += 2.0f;
			}
		}
	}

	// Set camera
	pCam->setOrthographic(-pCam->getScreenWidth() / 2.0f * zf, pCam->getScreenWidth() / 2.0f * zf,
		-pCam->getScreenHeight() / 2.0f * zf, pCam->getScreenHeight() / 2.0f * zf,
		1.0f, 1000.0f);
	pCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(xs, ys, -1.0f), Vect(xs, ys, 0.0f));

}

void AngryCamera::PanX(bool toRight)
{
	SetMode(Mode::Free);
	if (toRight)
	{
		Instance()->xShift += 9;
	}
	else
	{
		Instance()->xShift -= 9;
	}
}

void AngryCamera::PanY(bool toUp)
{
	SetMode(Mode::Free);
	if (toUp)
	{
		Instance()->yShift += 2;
	}
	else
	{
		Instance()->yShift -= 2;
	}
}

void AngryCamera::Zoom(bool in)
{
	SetMode(Mode::Free);
	if (in)
	{
		Instance()->zoomFactor -= 0.02f;
	}
	else
	{
		Instance()->zoomFactor += 0.02f;;
	}
}

void AngryCamera::SetMode(Mode _mode)
{
	Instance()->mode = _mode;
}

void AngryCamera::BirdFlying(Bird_Base* _pBird)
{
	Instance()->pBird = _pBird;
	Instance()->mode = Mode::Flying;
}

AngryCamera* AngryCamera::Instance()
{
		static AngryCamera angryCam;
		return &angryCam;
}

AngryCamera::AngryCamera()
	: mode(Mode::Free)
{

}

