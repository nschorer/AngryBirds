#ifndef ANGRY_CAMERA_H
#define ANGRY_CAMERA_H

class Camera;
class Bird_Base;

class AngryCamera {
public:

	enum class Mode {
		Waiting,
		Sling_Pulled,
		Flying,
		Collided,
		Free
	};

	static void Init(float x, float y, float zoom);
	static void Frame(Camera* pCam);

	static void PanX(bool toRight);
	static void PanY(bool toUp);
	static void Zoom(bool in);

	static void SetMode(Mode _mode);
	static void BirdFlying(Bird_Base* pBird);

private:
	AngryCamera();
	static AngryCamera* Instance();

	Mode mode;
	Bird_Base* pBird;
	float xShift;
	float yShift;
	float zoomFactor;
};

#endif

