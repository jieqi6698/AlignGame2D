#include "..\include\ag2d_launcher.h"
#include "..\include\ag2d_game.h"

using namespace ag2d;

//构造函数，必须标识这个场景的流程码
Ag2dGameScene::Ag2dGameScene(FlowCode code)
	:Ag2dScene(code),
	m_display_scene(NULL),
	m_bg_layer(NULL),
	m_wnd_layer(NULL),
	m_stage_layer(NULL),
	m_background(NULL),
	m_sprites_manager_duration(0.3f)//实际运行，须设置为0
{
	
}

//析构函数
Ag2dGameScene::~Ag2dGameScene()
{
	//释放资源
	m_display_scene->release();
	m_bg_layer->release();
	m_wnd_layer->release();
	m_stage_layer->release();
}

//场景内所有可显示元素，在此函数中绘制。
void Ag2dGameScene::draw(CCScene* display_scene)
{
	m_display_scene = display_scene;
	//两个层都是以左下角为直角坐标系原点，
	m_bg_layer = CCLayer::node();
	m_wnd_layer = CCLayer::node();
	//背景层不接收触摸处理
	m_bg_layer->setIsTouchEnabled(false);
	//如果默认存在背景参数，则把背景图首先绘制到背景层
	if(NULL != m_background)
	{
		CCSprite* background = CCSprite::spriteWithFile(m_background);
		background->setPosition(ccp(m_center_x,m_center_y));
		m_bg_layer->addChild(background,0,0);
	}
	//然后再绘制其它元素
	drawToBackgroundLayer(m_bg_layer);
	drawToWindowsLayer(m_wnd_layer);
	//刷新两个层
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallRefreshWindowsLayer),0.1f);
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallRefreshBackgroundLayer),0.1f);
	//添加到场景。
	display_scene->addChild(m_wnd_layer,WINDOWS_LAYER_TAG,WINDOWS_LAYER_Z_ORDER);
	display_scene->addChild(m_bg_layer,BG_LAYER_TAG,BG_LAYER_Z_ORDER);
}

//舞台层在被显示后才绘制
void Ag2dGameScene::didDisplayed()
{
	m_stage_layer = CCLayer::node();
	//添加舞台层到场景中
	m_display_scene->addChild(m_stage_layer,STAGE_LAYER_TAG,STAGE_LAYER_Z_ORDER);
	//更新精灵管理器
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallSpriteManager),m_sprites_manager_duration);
	//动作检测
	this->schedule(schedule_selector(Ag2dGameScene::scheduleCallActionSystem));
}

//读取数据通道数据，然后更新精灵到舞台中
//此函数在每一帧都被调用
void Ag2dGameScene::drawSpritesToStage(CCLayer* stage_layer)
{
	//读取数据通道数据，然后传给精灵管理器检验
	Ag2dSpritesManager sprites_manager = Ag2dLauncher::sharedSpritesManager();
	if(sprites_manager.validateOnFrame())
	{
		//更新发生改变的精灵组
		list<Ag2dSpriteNode*> target_array = sprites_manager.getChangedSpriteArray();
		//精灵状态发生的变化，在Ag2dSpriteNode中status标识。
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

//定时器需要的中间回调函数，用于调用drawSpritesToStage函数
void Ag2dGameScene::scheduleCallSpriteManager(ccTime time)
{
	drawSpritesToStage(m_stage_layer);
}

//定时器回舞台层的检测操作
void Ag2dGameScene::scheduleCallActionSystem(ccTime time)
{
	Ag2dSpritesManager sprites_manager = Ag2dLauncher::sharedSpritesManager();
	Ag2dActionSystem action_system = Ag2dLauncher::sharedActionSystem();
	//扫描数据通道中的主角与精灵。
	if(action_system.validateCrashAction(sprites_manager.getTotalSpriteArray()))
	{
		//从精灵管理器中取出发生碰撞的精灵数据，传给GameProcessor处理数据
		//m_game_processor->process(m_action_system->getCrashSprites());
	}
}

////初始化数据通道
void Ag2dGameScene::initial()
{
}

//清除定时器
void Ag2dGameScene::toDestory()
{
	this->unscheduleAllSelectors();
}

//定时器回调窗口层的刷新操作
void Ag2dGameScene::scheduleCallRefreshWindowsLayer(ccTime time)
{
	updateBackgroundLayer(m_bg_layer);
}
		
//定时器回调背景层的刷新操作
void Ag2dGameScene::scheduleCallRefreshBackgroundLayer(ccTime time)
{
	updateWindowsLayer(m_wnd_layer);
}