#pragma once
#include <OGL3D/All.h>

//disse tingene er ubrukt jeg fikk ikke gjøre noe med det
class MyPlayer : public OEntity
{
public:
	MyPlayer();
	~MyPlayer();

	virtual void onCreate();
	virtual void onUpdate(f32 deltaTime);

private:
	f32 m_elapsedSeconds = 0.0f;
	OEntity* m_entity = nullptr;
};