#include "..\common\ag2d_splashscene.h"

using namespace ag2d;

Ag2dSplashScene::Ag2dSplashScene(FlowCode code,char* splash)
	:Ag2dCommonScene(code),
	m_splash_image(splash),
	m_listener(NULL),
	m_loading_icon(NULL)
{
}

void Ag2dSplashScene::setLoadingListener(Ag2dSplashListener& listener)
{
	m_listener = &listener;
}

void Ag2dSplashScene::setLoadingIcon(char* load_icon)
{
	m_loading_icon = load_icon;
}

void Ag2dSplashScene::updateBackgroundLayer(CCLayer& bg_layer)
{
}

void Ag2dSplashScene::updateWindowsLayer(CCLayer& wnd_layer)
{
}

void Ag2dSplashScene::drawToWindowsLayer(CCLayer& wnd_layer)
{
}
		
void Ag2dSplashScene::drawToBackgroundLayer(CCLayer& bg_layer)
{
	CCSprite* bg = CCSprite::spriteWithFile(m_splash_image);
	bg->setPosition(ccp(m_center_x,m_center_y));
	bg_layer.addChild(bg);
	bg->runAction(CCFadeIn::actionWithDuration(0.5f));
	
	if(NULL != m_loading_icon)
	{
		CCSprite* loading_icon = CCSprite::spriteWithFile(m_loading_icon);
		int padding = 5;
		float x = m_measure_width - loading_icon->getContentSize().width/2 - padding;
		float y = loading_icon->getContentSize().height - padding;
		loading_icon->setPosition(ccp(x,y));
		loading_icon->runAction(CCRepeatForever::actionWithAction(CCRotateBy::actionWithDuration(3 , 360)));
		bg_layer.addChild(loading_icon);
	}
	//启动加载过程
	if( NULL!= m_listener) m_listener->onLoading();

	//中转到下一个场景

}
