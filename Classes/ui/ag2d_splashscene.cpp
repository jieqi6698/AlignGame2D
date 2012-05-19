#include "..\common\ag2d_splashscene.h"

using namespace ag2d;

Ag2dSplashScene::Ag2dSplashScene(FlowCode code)
	:Ag2dCommonScene(code),
	m_splash_list(NULL),
	m_splash_index(0)
{
	m_splash_list = new list<char*>;
}

void Ag2dSplashScene::setSplashRes(char* splash)
{
	m_splash_list->push_back(splash);
	m_splash_index++;
}

void Ag2dSplashScene::updateBackgroundLayer(CCLayer& bg_layer)
{
		
}

void Ag2dSplashScene::updateWindowsLayer(CCLayer& wnd_layer)
{
		
}
		
void Ag2dSplashScene::drawToBackgroundLayer(CCLayer& bg_layer)
{
	CCSprite* bg = CCSprite::spriteWithFile("background.jpg");
	bg->setPosition(ccp(m_center_x,m_center_y));
	bg_layer.addChild(bg);

	this->schedule(schedule_selector(Ag2dSplashScene::splashCallback),2.5f);
}

void Ag2dSplashScene::splashCallback(ccTime timc)
{
	CCLOG("Splash Callback");
}

void Ag2dSplashScene::drawToWindowsLayer(CCLayer& wnd_layer)
{
		
}