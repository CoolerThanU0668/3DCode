#pragma once
#include <OGL3D/All.h>
#include "MyPlayer.h"

//mest av disse tingene er ubrukt jeg fikk ikke gjøre noe med det
class MyGame : public OGame
{
public:
	MyGame();
	~MyGame();

	virtual void onCreate();
	virtual void onUpdate(f32 deltaTime);

private:
	f32 m_elapsedSeconds = 0.0f;
	MyPlayer* m_player = nullptr;
};