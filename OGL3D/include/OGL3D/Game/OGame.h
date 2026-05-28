#pragma once
#include <OGL3D/OPrerequisites.h>
#include <memory>
#include <chrono>
#include <InputSystem/InputListener.h>
#include <OGL3D/Math/OMat4.h>

class OGraphicsEngine;
class OEntitySystem;
class OWindow;
class OGame: public InputListener
{
public:
	OGame();
	virtual ~OGame();

	void run();
	void quit();

	OEntitySystem* getEntitySystem();

	void onKeyDown(int key) override;
	void onKeyUp(int key) override;

	OMat4 world, projection, temp;

protected:
	virtual void onCreate();
	virtual void onUpdate(f32 deltaTime) {}
	virtual void onQuit();


private:
	void onUpdateInternal();

	bool m_isRunning = true;	

    std::unique_ptr<OGraphicsEngine> m_graphicsEngine;
	std::unique_ptr<OWindow> m_display;	
	std::unique_ptr<OEntitySystem> m_entitySystem;

	OVertexArrayObjectPtr m_polygonVAO;
	OUniformBufferPtr m_uniform;
	OShaderProgramPtr m_shader;

	std::chrono::system_clock::time_point m_previousTime;
	f32 m_scale = -3;

	f32 m_posX = 0;
	f32 m_posY = 0;
	f32 m_posZ = 0;

	f32 m_rotX = 0;
	f32 m_rotY = 0;
	f32 m_rotZ = 0;

};

