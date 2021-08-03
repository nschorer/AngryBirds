#include <sb6.h>
#include <sb6ktx.h>
#include <math.h>
#include <assert.h>

#include "DebugOut.h"
#include "GameObject.h"
#include "MathEngine.h"
#include "Game.h"
#include "GraphicsObject.h"
#include "GraphicsObject_Sprite.h"
#include "GraphicsObject_Circle.h"
#include "GraphicsObject_Box.h"
#include "GraphicsObject_Tri.h"
#include "TextureMan.h"
#include "Camera.h"
#include "GameObjectMan.h"
#include "CameraMan.h"
#include "Image.h"
#include "GameObject2D.h"
#include "Color.h"
#include "Vect2D.h"
#include "ShaderMan.h"
#include "ImageMan.h"
#include "DebugOut.h"
#include "ModelMan.h"
#include "AzulStopWatch.h"
#include "TimerMan.h"
#include "Keyboard.h"
#include "Mouse.h"

Game* Game::ptrInstance = nullptr;

//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "PixelToMeter.h"
#include "PhysicsMan.h"
#include "BirdsPigsHeader.h"
#include "WoodPlatform.h"
#include "BlocksHeader.h"
#include "TowersHeader.h"
#include "Floor.h"
#include "Slingshot.h"
#include "BirdQueue.h"
#include "ImageLoader.h"
#include "AngryCamera.h"
#include "AngryContactListener.h"
#include "AudioManager.h"
#include "DeathZone.h"

#include "Lander1.h"
#include "Lander2.h"
#include "Seesaw.h"
#include "FerrisWheel.h"


#include "Visualizer.h"
#include "NinjaSword.h"
#include "SimpleRaycastCallback.h"
#include "NinjaSwordCallback.h"
#include "NinjaHeader.h"
#include "NinjaLauncher.h"

AngryContactListener* pMyContactListener;
BlackBird* pBlackBird;
Slingshot* pSlingshot;
BirdQueue* pBirdQueue;
NinjaLauncher* pLauncher;

SimpleRayCastCallBack* pSimpleRCCB;
NinjaSwordCallback* pNinjaRCCB;

//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game(const char* windowName, const int Width, const int Height)
	:Engine(windowName, Width, Height)
{
	ptrInstance = this;
	screenWidth = static_cast<float>(Width);
	screenHeight = static_cast<float>(Height);
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	// Initialize timer
	AzulStopWatch::initStopWatch();

	// Start timer
	stopWatch.tic();
	totalWatch.tic();

	//---------------------------------------------------------------------------------------------------------
	// Box2D setup
	//---------------------------------------------------------------------------------------------------------

	PhysicsMan::Create();
	PhysicsWorld* pWorld = new PhysicsWorld(-10.0f, 50);
	PhysicsMan::AddWorld(pWorld);
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	//---------------------------------------------------------------------------------------------------------
	// Setup the current 2D orthographic Camera
	//---------------------------------------------------------------------------------------------------------
	Camera* pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

	float zoomFactor = 2.0f;
	float xShift = 200.0f;
	float yShift = -50.0f;

	pCam2D->setViewport(0, 0, (int)this->screenWidth, (int)this->screenHeight);
	pCam2D->setOrthographic(-pCam2D->getScreenWidth() / 2.0f * zoomFactor, pCam2D->getScreenWidth() / 2.0f * zoomFactor,
		-pCam2D->getScreenHeight() / 2.0f * zoomFactor, pCam2D->getScreenHeight() / 2.0f * zoomFactor,
		1.0f, 1000.0f);
	//pCam2D->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, -1.0f), Vect(0.0f, 0.0f, 0.0f));
	pCam2D->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(xShift, yShift, -1.0f), Vect(xShift, yShift, 0.0f));

	// Holder for the current 2D  cameras
	CameraMan::SetCurrentCamera(pCam2D, Camera::Type::ORTHOGRAPHIC_2D);

	AngryCamera::Init(xShift, yShift, zoomFactor);

	//---------------------------------------------------------------------------------------------------------
	// Load up the managers
	//---------------------------------------------------------------------------------------------------------
		// Create/Load Shader 
	ShaderMan::addShader(ShaderName::SPRITE, "spriteRender");
	ShaderMan::addShader(ShaderName::SPRITE_LINE, "spriteLineRender");

	// Textures
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/unsorted.tga", TextName::BirdPigsEffects);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/woodBlocks.tga", TextName::WoodBlocks);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/glassBlocks.tga", TextName::GlassBlocks);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/stoneBlocks.tga", TextName::StoneBlocks);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/AngryBirdBackground.tga", TextName::AngryBackground);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/woodPlatform.tga", TextName::WoodPlatform);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/slingV2.tga", TextName::SlingV2);

	// Images
	LoadImages();

	// Startup audio
	AudioManager::Initialize();

	//---------------------------------------------------------------------------------------------------------
	// Sort buckets (AKA sprite layers)
	//---------------------------------------------------------------------------------------------------------
	GameSortBucket* pSortBkt;

	pSortBkt = new GameSortBucket(GameObjectName::Slong_Handle_Front);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Sling_Front);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::MainGroup);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::TowerGroup);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Effects);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::SmokeTrail);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::PredictionGroup);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Sling_Handle_Back);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Sling_Back);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::TowerBackground);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Background);
	GameObjectMan::Add(pSortBkt);

	//---------------------------------------------------------------------------------------------------------
	// Create Sprites
	//---------------------------------------------------------------------------------------------------------

	CreateGameObjects();

	// create and initialize contact listener
	pMyContactListener = new AngryContactListener();
	PhysicsMan::GetWorld()->GetWorld()->SetContactListener(pMyContactListener);

	/*pSimpleRCCB = new SimpleRayCastCallBack();
	pNinjaRCCB = new NinjaSwordCallback();

	pLauncher = new NinjaLauncher(1400.0f, 100.0f, 300.0f, PhysicsMan::GetWorld());*/
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update(float currentTime)
{
	// Time update.
	//      Get the time that has passed.
	//      Feels backwards, but its not, need to see how much time has passed
	stopWatch.toc();
	stopWatch.tic();
	totalWatch.toc();

	// Update cameras - make sure everything is consistent
	Camera* pCam2D = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	AngryCamera::Frame(pCam2D);
	pCam2D->updateCamera();

	TimerMan::Update();

	ProcessInputs();
	//NinjaAction(pNinjaRCCB);

	// -------------  Add your update below this line: ----------------------------

	PhysicsMan::Update(); //currentTime
	GameObjectMan::Update(currentTime);

	GameObjectMan::DeletePending();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	// draw all objects
	GameObjectMan::Draw();
	
	/*if (Keyboard::GetKeyState(AZUL_KEY::KEY_LEFT_SHIFT))
	{
		Visualizer::Render();
	}*/
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{

	delete pBirdQueue;
	delete pSimpleRCCB;
	delete pNinjaRCCB;
	delete pLauncher;

	Visualizer::Terminate();

	// Engine clean-up
	CameraMan::Terminate();
	ModelMan::Terminate();
	ShaderMan::Terminate();
	TextureMan::Terminate();
	ImageMan::Terminate();

	GameObjectMan::Terminate();
	TimerMan::Terminate();

	delete pMyContactListener;
	PhysicsMan::Terminate();
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
	const GLfloat blue[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, blue);
	glClearBufferfv(GL_DEPTH, 0, &one);
}

void Game::CreateGameObjects()
{
	PhysicsObject2D* pPhysObj;
	PhysicsWorld* pWorld = PhysicsMan::GetWorld();

	//----------------------------------------------------------------------------------------
	// Tower
	//----------------------------------------------------------------------------------------

	
	//----------------------------------------------------------------------------------------
	// Environment
	//----------------------------------------------------------------------------------------

	pBirdQueue = new BirdQueue(3, 100.0f, 25.0f, pWorld);

	pPhysObj = new Floor(800.0f, -40.0f, 2500.0f, 100.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::Background);

	GameObject2D* pGameObj;

	pSlingshot = new Slingshot(200.0f, 100.0f, pBirdQueue);
	pGameObj = pSlingshot;
	GameObjectMan::Add(pGameObj, GameObjectName::MainGroup);
	//pSlingshot->LoadBird(pBird);

	//pSlingshot->LoadBird(pBird);

	pGameObj = new DeathZone( 2000, 0, 500, 2000, pWorld);
	GameObjectMan::Add(pGameObj, GameObjectName::Background);

	pGameObj = new DeathZone(-500.0f, 0, 500, 2000, pWorld);
	GameObjectMan::Add(pGameObj, GameObjectName::Background);

	pGameObj = new GameObject2D(GameObjectName::Background, new GraphicsObject_Sprite(ImageName::BG_0, Rect(200, 250, 1280, 1336)));
	GameObjectMan::Add(pGameObj, GameObjectName::Background);

	pGameObj = new GameObject2D(GameObjectName::Background, new GraphicsObject_Sprite(ImageName::BG_0, Rect(200 + 1280, 250, 1280, 1336)));
	GameObjectMan::Add(pGameObj, GameObjectName::Background);
}

void Game::ProcessInputs()
{
	//-----------------------------------------------------------
	// Keyboard reading
	//-----------------------------------------------------------

	static bool onePressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_1))
	{
		if (!onePressed)
		{
			BuildTower_Queue(Tower::ONE);
		}
		onePressed = true;
	}
	else
	{
		onePressed = false;
	}

	static bool twoPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_2))
	{
		if (!twoPressed)
		{
			BuildTower_Queue(Tower::TWO);
		}
		twoPressed = true;
	}
	else
	{
		twoPressed = false;
	}

	static bool threePressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_3))
	{
		if (!threePressed)
		{
			BuildTower_Queue(Tower::THREE);
		}
		threePressed = true;
	}
	else
	{
		threePressed = false;
	}

	static bool fourPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_4))
	{
		if (!fourPressed)
		{
			BuildTower_Queue(Tower::FOUR);
		}
		fourPressed = true;
	}
	else
	{
		fourPressed = false;
	}

	static bool fivePressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_5))
	{
		if (!fivePressed)
		{
			BuildTower_Queue(Tower::FIVE);
		}
		fivePressed = true;
	}
	else
	{
		fivePressed = false;
	}

	static bool rPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		if (!rPressed)
		{
			pBirdQueue->Reload(BirdQueue::Type::RED);
			pSlingshot->LoadBirdFromQueue();

		}
		rPressed = true;
	}
	else
	{
		rPressed = false;
	}

	static bool tPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_T))
	{
		if (!tPressed)
		{
			pBirdQueue->Reload(BirdQueue::Type::BLACK);
			pSlingshot->LoadBirdFromQueue();

		}
		tPressed = true;
	}
	else
	{
		tPressed = false;
	}

	static bool yPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_Y))
	{
		if (!yPressed)
		{
			pBirdQueue->Reload(BirdQueue::Type::YELLOW);
			pSlingshot->LoadBirdFromQueue();

		}
		yPressed = true;
	}
	else
	{
		yPressed = false;
	}

	static bool uPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_U))
	{
		if (!uPressed)
		{
			pBirdQueue->Reload(BirdQueue::Type::WHITE);
			pSlingshot->LoadBirdFromQueue();

		}
		uPressed = true;
	}
	else
	{
		uPressed = false;
	}

	static bool iPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
	{
		if (!iPressed)
		{
			pBirdQueue->Reload(BirdQueue::Type::GREEN);
			pSlingshot->LoadBirdFromQueue();

		}
		iPressed = true;
	}
	else
	{
		iPressed = false;
	}

	static bool oPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_O))
	{
		if (!oPressed)
		{
			pBirdQueue->Reload(BirdQueue::Type::BLUE);
			pSlingshot->LoadBirdFromQueue();

		}
		oPressed = true;
	}
	else
	{
		oPressed = false;
	}

	static bool pPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_P))
	{
		if (!pPressed)
		{
			pBirdQueue->Reload(BirdQueue::Type::BIG);
			pSlingshot->LoadBirdFromQueue();

		}
		pPressed = true;
	}
	else
	{
		pPressed = false;
	}

	static bool homePressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_HOME))
	{
		if (!homePressed)
		{
			CleanupTower();
			Bird_Base::CleanupBirds();
		}
		homePressed = true;
	}
	else
	{
		homePressed = false;
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		AngryCamera::PanX(false);
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		AngryCamera::PanX(true);
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
	{
		AngryCamera::PanY(true);
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		AngryCamera::PanY(false);
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_MINUS))
	{
		AngryCamera::Zoom(false);
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_EQUAL))
	{
		AngryCamera::Zoom(true);
	}

	static bool mPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_M))
	{
		if (!mPressed)
		{
			AudioManager::ToggleMusic();
		}
		mPressed = true;
	}
	else
	{
		mPressed = false;
	}
}

float Game::GetFrameTime()
{
	return Instance().stopWatch.timeInSeconds();
}

float Game::GetTotalTime()
{
	return Instance().totalWatch.timeInSeconds();
}

Game::~Game()
{
	//delete pWorld;
}

void Game::Run(const char* windowName, const int Width, const int Height)
{
	ptrInstance = new Game(windowName, Width, Height);
	ptrInstance->run();
	delete ptrInstance;
}
