
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

//��ʼ������
void Ag2dEngine::start()
{
	CCDirector* director = CCDirector::sharedDirector();
	//��ʼ����������
	director->setOpenGLView(&CCEGLView::sharedOpenGLView());
	director->enableRetinaDisplay(CONF_ENABLE_RETINA);
	director->setDisplayFPS(CONF_SHOW_FPS);
	director->setAnimationInterval(CONF_FPS_VAL);	
	
	//����
	playScene( reg_scene );
}

//���г���
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

//ע�᳡��
void Ag2dEngine::registerScene(Ag2dScene* scene)
{
	reg_scene = scene;
}

//��ͣ����
void Ag2dEngine::pause()
{
	 SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	CCDirector::sharedDirector()->pause();
}

//�ָ�����
void Ag2dEngine::resume()
{
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	CCDirector::sharedDirector()->resume();
}

//ֹͣ����
void Ag2dEngine::end()
{
	SimpleAudioEngine::end();
	CCDirector::sharedDirector()->end();
}

//�ı䳡�����̡����������ʹ���������任
void Ag2dEngine::changeSceneFlow(FlowCode code)
{
	// later
	//CCDirector::sharedDirector()->getRunningScene()->getChildByTag();
}
