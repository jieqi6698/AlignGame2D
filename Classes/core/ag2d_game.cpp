#include "..\include\ag2d_launcher.h"
#include "..\include\ag2d_game.h"

using namespace ag2d;

//���캯���������ʶ���������������
Ag2dGameScene::Ag2dGameScene(FlowCode code)
	:Ag2dScene(code),
	m_display_scene(NULL),
	m_bg_layer(NULL),
	m_wnd_layer(NULL),
	m_stage_layer(NULL),
	m_background(NULL),
	m_sprites_manager_duration(0.3f)//ʵ�����У�������Ϊ0
{
	
}

//��������
Ag2dGameScene::~Ag2dGameScene()
{
	//�ͷ���Դ
	m_display_scene->release();
	m_bg_layer->release();
	m_wnd_layer->release();
	m_stage_layer->release();
}

//���������п���ʾԪ�أ��ڴ˺����л��ơ�
void Ag2dGameScene::draw(CCScene* display_scene)
{
	m_display_scene = display_scene;
	//�����㶼�������½�Ϊֱ������ϵԭ�㣬
	m_bg_layer = CCLayer::node();
	m_wnd_layer = CCLayer::node();
	//�����㲻���մ�������
	m_bg_layer->setIsTouchEnabled(false);
	//���Ĭ�ϴ��ڱ�����������ѱ���ͼ���Ȼ��Ƶ�������
	if(NULL != m_background)
	{
		CCSprite* background = CCSprite::spriteWithFile(m_background);
		background->setPosition(ccp(m_center_x,m_center_y));
		m_bg_layer->addChild(background,0,0);
	}
	//Ȼ���ٻ�������Ԫ��
	drawToBackgroundLayer(m_bg_layer);
	drawToWindowsLayer(m_wnd_layer);
	//ˢ��������
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallRefreshWindowsLayer),0.1f);
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallRefreshBackgroundLayer),0.1f);
	//��ӵ�������
	display_scene->addChild(m_wnd_layer,WINDOWS_LAYER_TAG,WINDOWS_LAYER_Z_ORDER);
	display_scene->addChild(m_bg_layer,BG_LAYER_TAG,BG_LAYER_Z_ORDER);
}

//��̨���ڱ���ʾ��Ż���
void Ag2dGameScene::didDisplayed()
{
	m_stage_layer = CCLayer::node();
	//�����̨�㵽������
	m_display_scene->addChild(m_stage_layer,STAGE_LAYER_TAG,STAGE_LAYER_Z_ORDER);
	//���¾��������
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallSpriteManager),m_sprites_manager_duration);
	//�������
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallActionSystem));
}

//��ȡ����ͨ�����ݣ�Ȼ����¾��鵽��̨��
//�˺�����ÿһ֡��������
void Ag2dGameScene::drawSpritesToStage(CCLayer* stage_layer)
{
	//��ȡ����ͨ�����ݣ�Ȼ�󴫸��������������
	Ag2dSpritesManager sprites_manager = Ag2dLauncher::sharedSpritesManager();
	if(sprites_manager.validateOnFrame())
	{
		//���·����ı�ľ�����
		list<Ag2dSpriteNode*> target_array = sprites_manager.getChangedSpriteArray();
		//����״̬�����ı仯����Ag2dSpriteNode��status��ʶ��
		list<Ag2dSpriteNode*>::iterator it;
		for (it = target_array.begin(); it != target_array.end(); it++)
		{
			Ag2dSpriteNode& node = *(*it);
			if(node.status == SS_NEW)
			{
				CCNode* sprite = node.sprite;
				sprite->setPosition(node.position);
				stage_layer->addChild(sprite,node.zOrder,node.tag);
				sprite->runAction(node.action);
			}else if(node.status == SS_DEL)
			{
				stage_layer->removeChildByTag(node.tag,true);
				sprites_manager.removeSprite(node.tag);
			}else if(node.status = SS_VISIBLE)
			{
				CCNode* sprite = stage_layer->getChildByTag(node.tag);
				if(NULL != sprite)
				{
					sprite->setIsVisible(!sprite->getIsVisible());
				}
			}
		}//end for
	}
}

//��ʱ����Ҫ���м�ص����������ڵ���drawSpritesToStage����
void Ag2dGameScene::scheduleCallSpriteManager(ccTime time)
{
	drawSpritesToStage(m_stage_layer);
}

//��ʱ������̨��ļ�����
void Ag2dGameScene::scheduleCallActionSystem(ccTime time)
{
	Ag2dSpritesManager sprites_manager = Ag2dLauncher::sharedSpritesManager();
	Ag2dActionSystem action_system = Ag2dLauncher::sharedActionSystem();
	//ɨ������ͨ���е������뾫�顣
	if(action_system.validateCrashAction(sprites_manager.getTotalSpriteArray()))
	{
		//�Ӿ����������ȡ��������ײ�ľ������ݣ�����GameProcessor��������
		//m_game_processor->process(m_action_system->getCrashSprites());
	}
}

////��ʼ������ͨ��
void Ag2dGameScene::initial()
{
}

//�����ʱ��
void Ag2dGameScene::toDestory()
{
	this->unscheduleAllSelectors();
}

//��ʱ���ص����ڲ��ˢ�²���
void Ag2dGameScene::scheduleCallRefreshWindowsLayer(ccTime time)
{
	updateBackgroundLayer(m_bg_layer);
}
		
//��ʱ���ص��������ˢ�²���
void Ag2dGameScene::scheduleCallRefreshBackgroundLayer(ccTime time)
{
	updateWindowsLayer(m_wnd_layer);
}