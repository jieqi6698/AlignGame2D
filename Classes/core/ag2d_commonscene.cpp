#include "..\include\ag2d_commonscene.h"

using namespace ag2d;

//�������̱��л����˳������������ȵ��ô˺����Գ������г�ʼ������ʱ��������û�б���ʾ��
void Ag2dCommonScene::initial()
{
	m_action_system = &Ag2dLauncher::sharedActionSystem();
	m_sprites_manager = &Ag2dLauncher::sharedSpritesManager();
};

//���캯���������ʶ���������������
Ag2dCommonScene::Ag2dCommonScene(FlowCode code)
	:Ag2dScene(code)
{

};

//��������
Ag2dCommonScene::~Ag2dCommonScene()
{
};

////���������п���ʾԪ�أ��ڴ˺����л��ơ�
void Ag2dCommonScene::draw(CCScene& display_scene)
{
	//�����㶼�������½�Ϊֱ������ϵԭ��
	m_bg_layer = CCLayer::node();
	m_wnd_layer = CCLayer::node();
	m_bg_layer->setIsTouchEnabled(false);
	display_scene.addChild(m_bg_layer,BG_LAYER_TAG,BG_LAYER_Z_ORDER);
	display_scene.addChild(m_wnd_layer,WINDOWS_LAYER_TAG,WINDOWS_LAYER_Z_ORDER);
	drawToBackgroundLayer( * m_bg_layer);
	drawToWindowsLayer( * m_wnd_layer);
	this->schedule(schedule_selector(Ag2dCommonScene::scheduleCallback),0.1f);
};

//��ÿһ֡�лص�
void Ag2dCommonScene::scheduleOnPerFrame(ccTime timc)
{
	if(m_action_system->isAction())
	{
		m_sprites_manager->updateToStage( * m_stage_layer);
	}
};

//�����Ѿ���������ȵ���ʾ��������ʾ���˺���������
void Ag2dCommonScene::didDisplayed()
{
	m_stage_layer = CCLayer::node();
	m_display_scene->addChild(m_stage_layer,STAGE_LAYER_TAG,STAGE_LAYER_Z_ORDER);
	m_sprites_manager->drawToStage( * m_stage_layer);
};

//�������̱�����˳������������������٣��˺��������á�
void Ag2dCommonScene::toDestory()
{
	this->unscheduleAllSelectors();
};

//��ʱ�ص�
void Ag2dCommonScene::scheduleCallback(ccTime time)
{
	updateBackgroundLayer( * m_bg_layer);
	updateWindowsLayer( * m_wnd_layer);
};
