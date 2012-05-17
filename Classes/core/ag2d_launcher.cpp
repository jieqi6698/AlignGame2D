#include "..\include\ag2d_launcher.h"

using namespace ag2d;

Ag2dEngine* Ag2dLauncher::m_engine = NULL;
Ag2dSpritesManager* Ag2dLauncher::m_sprites_manager = NULL;
Ag2dActionSystem* Ag2dLauncher::m_action_system = NULL;
Ag2dDataChannel* Ag2dLauncher::m_data_channel = NULL;

void Ag2dLauncher::init()
{
	m_engine = new Ag2dEngine();
	m_sprites_manager = new Ag2dSpritesManager();
	m_action_system = new Ag2dActionSystem();
}

void Ag2dLauncher::destory()
{
	delete m_engine;
}

//引擎
Ag2dEngine& Ag2dLauncher::sharedEngine()
{
	return * m_engine;
}

//精灵管理器
Ag2dSpritesManager& Ag2dLauncher::sharedSpritesManager()
{
	return * m_sprites_manager;
}

//动作系统
Ag2dActionSystem* Ag2dLauncher::sharedActionSystem()
{
	return m_action_system;
}

//数据通道
Ag2dDataChannel* Ag2dLauncher::sharedDataChannel()
{
	return m_data_channel;
}