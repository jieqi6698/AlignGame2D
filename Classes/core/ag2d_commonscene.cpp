#include "..\include\ag2d_commonscene.h"

using namespace ag2d;

//引擎流程被切换到此场景，引擎首先调用此函数对场景进行初始化。此时，场景还没有被显示。
void Ag2dCommonScene::initial()
{
	m_action_system = &Ag2dLauncher::sharedActionSystem();
	m_sprites_manager = &Ag2dLauncher::sharedSpritesManager();
};

//构造函数，必须标识这个场景的流程码
Ag2dCommonScene::Ag2dCommonScene(FlowCode code)
	:Ag2dScene(code)
{

};

//析构函数
Ag2dCommonScene::~Ag2dCommonScene()
{
};

////场景内所有可显示元素，在此函数中绘制。
void Ag2dCommonScene::draw(CCScene& display_scene)
{
	//两个层都是以左下角为直角坐标系原点
	m_bg_layer = CCLayer::node();
	m_wnd_layer = CCLayer::node();
	m_bg_layer->setIsTouchEnabled(false);
	display_scene.addChild(m_bg_layer,BG_LAYER_TAG,BG_LAYER_Z_ORDER);
	display_scene.addChild(m_wnd_layer,WINDOWS_LAYER_TAG,WINDOWS_LAYER_Z_ORDER);
	drawToBackgroundLayer( * m_bg_layer);
	drawToWindowsLayer( * m_wnd_layer);
	this->schedule(schedule_selector(Ag2dCommonScene::scheduleCallback),0.1f);
};

//在每一帧中回调
void Ag2dCommonScene::scheduleOnPerFrame(ccTime timc)
{
	if(m_action_system->isAction())
	{
		m_sprites_manager->updateToStage( * m_stage_layer);
	}
};

//场景已经被引擎调度到显示窗口中显示，此函数被调用
void Ag2dCommonScene::didDisplayed()
{
	m_stage_layer = CCLayer::node();
	m_display_scene->addChild(m_stage_layer,STAGE_LAYER_TAG,STAGE_LAYER_Z_ORDER);
	m_sprites_manager->drawToStage( * m_stage_layer);
};

//引擎流程被调离此场景，场景即将被销毁，此函数被调用。
void Ag2dCommonScene::toDestory()
{
	this->unscheduleAllSelectors();
};

//定时回调
void Ag2dCommonScene::scheduleCallback(ccTime time)
{
	updateBackgroundLayer( * m_bg_layer);
	updateWindowsLayer( * m_wnd_layer);
};
