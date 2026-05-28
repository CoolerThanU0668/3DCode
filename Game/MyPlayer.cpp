#include "MyPlayer.h"
#include <OGL3D/Math/OVec2.h>
#include <OGL3D/Math/OVec3.h>
#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>
#include <OGL3D/Graphics/OVertexArrayObject.h>
#include <OGL3D/Graphics/OShaderProgram.h>
#include <OGL3D/Graphics/OUniformBuffer.h>
#include <OGL3D/Graphics/OGraphicsEngine.h>
#include <OGL3D/Math/OMat4.h>
#include <OGL3D/Entity/OEntity.h>
#include <OGL3D/Entity/OEntitySystem.h>
#include <Windows.h>

//disse tingene er ubrukt jeg fikk ikke gjøre noe med det
MyPlayer::MyPlayer()
{
}

MyPlayer::~MyPlayer()
{
}

void MyPlayer::onCreate()
{
	m_entity = getEntitySystem()->createEntity<OEntity>();
}

void MyPlayer::onUpdate(f32 deltaTime)
{

}