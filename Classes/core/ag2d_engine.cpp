
#include "..\include\ag2d_engine.h"
#include "..\include\ag2d_config.h"

using namespace ag2d;

Ag2dEngine::Ag2dEngine()
	:m_running_scene(NULL)
{

}

bool Ag2dEngine::init()
{
   bool bRet = false;
   do
   {
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
			CCEGLView * pMainWnd = new CCEGLView();
			CC_BREAK_IF(! pMainWnd || ! pMainWnd->Create(TEXT(APP_TITLE), CONF_WND_WIDTH, CONF_WND_HEIGHT));
	#endif
	bRet = true;
	} while (0);
	return bRet;
}

//初始化引擎
void Ag2dEngine::start()
{
	CCDirector* director = CCDirector::sharedDirector();
	//初始化场景导演
	director->setOpenGLView(&CCEGLView::sharedOpenGLView());
	director->enableRetinaDisplay(CONF_ENABLE_RETINA);
	director->setDisplayFPS(CONF_SHOW_FPS);
	director->setAnimationInterval(CONF_FPS_VAL);	
	
	//启动
	playScene( reg_scene );
}

//运行场景
void Ag2dEngine::playScene(Ag2dScene* scene)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	scene->initMeasure(size.width,size.height);
	scene->initial();
	
	CCScene* display = scene->createDisplay();
	if(NULL != m_running_scene)
	{
		m_running_scene->toDestory();
		CCTransitionFade* fade = CCTransitionFade::transitionWithDuration(CONF_SCENE_DURATION, display);
		CCDirector::sharedDirector()->replaceScene(fade);
	}else
	{
		CCLOG(">>>>>>>> runWithScene >>>>>");
		CCDirector::sharedDirector()->runWithScene(display);
	}
	scene->didDisplayed();
	m_running_scene = scene;
}

//注册场景
void Ag2dEngine::registerScene(Ag2dScene* scene)
{
	reg_scene = scene;
}

//暂停引擎
void Ag2dEngine::pause()
{
	 SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	CCDirector::sharedDirector()->pause();
}

//恢复引擎
void Ag2dEngine::resume()
{
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	CCDirector::sharedDirector()->resume();
}

//停止引擎
void Ag2dEngine::end()
{
	SimpleAudioEngine::end();
	CCDirector::sharedDirector()->end();
}

//改变场景流程。这个动作会使场景发生变换
void Ag2dEngine::changeSceneFlow(FlowCode code)
{
	// later
	//CCDirector::sharedDirector()->getRunningScene()->getChildByTag();
}
