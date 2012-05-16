#ifndef _AG2D_COMMONSCENE_H_
#define _AG2D_COMMONSCENE_H_

#include "cocos2d.h"
#include "ag2d_launcher.h"
#include "ag2d_scene.h"
USING_NS_CC;

namespace ag2d
{

	class Ag2dCommonScene : public Ag2dScene
	{
	private:
		//背景层对象指针
		CCLayer* m_bg_layer;
		//窗口层对象指针
		CCLayer* m_wnd_layer;
		//精灵舞台怪
		CCLayer* m_stage_layer;

		//背景层标识
		static const int BG_LAYER_TAG = 0xA06E0;
		//背景层Z-Order
		static const int BG_LAYER_Z_ORDER = 0;

		//舞台层标识
		static const int STAGE_LAYER_TAG = 0xA06E1;
		//舞台层Z-Order
		static const int STAGE_LAYER_Z_ORDER = 1;

		//窗口层标识
		static const int WINDOWS_LAYER_TAG = 0xA06E2;
		//窗口层Z-Order
		static const int WINDOWS_LAYER_Z_ORDER = 2;

	protected:
		Ag2dActionSystem* m_action_system;
		Ag2dSpritesManager* m_sprites_manager;

	public:
		//引擎流程被切换到此场景，引擎首先调用此函数对场景进行初始化。此时，场景还没有被显示。
		void initial()
		{
			m_action_system = Ag2dLauncher::sharedActionSystem();
		};

		//构造函数，必须标识这个场景的流程码
		Ag2dCommonScene(FlowCode code):Ag2dScene(code){};

		//析构函数
		~Ag2dCommonScene()
		{
		};

		////场景内所有可显示元素，在此函数中绘制。
		void draw(CCScene* display_scene)
		{
			//两个层都是以左下角为直角坐标系原点，
			m_bg_layer = CCLayer::node();
			m_wnd_layer = CCLayer::node();
			//背景层不接收触摸处理
			m_bg_layer->setIsTouchEnabled(false);
			drawToBackgroundLayer(m_bg_layer);
			drawToWindowsLayer(m_wnd_layer);
			this->schedule(schedule_selector(Ag2dCommonScene::updateCallback),0.1f);
		};

		//在每一帧中回调
		void scheduleOnFrame(ccTime timc)
		{
			//调度动作系统、精灵管理器检验
			m_action_system->validate();
			m_sprites_manager->validate();
		};

		//场景已经被引擎调度到显示窗口中显示，此函数被调用
		void didDisplayed()
		{
			m_stage_layer = CCLayer::node();
			m_display_scene->addChild(m_stage_layer,STAGE_LAYER_TAG,STAGE_LAYER_Z_ORDER);
			m_sprites_manager->drawToStage(m_stage_layer);
			this->schedule(schedule_selector(Ag2dCommonScene::updateStageCallback));
		};

		//引擎流程被调离此场景，场景即将被销毁，此函数被调用。
		void toDestory()
		{
			this->unscheduleAllSelectors();
		};

		//定时回调
		void updateCallback(ccTime time)
		{
			updateBackgroundLayer(m_bg_layer);
			updateWindowsLayer(m_wnd_layer);
		};

		void updateStageCallback(ccTime time)
		{
			if(m_action_system->isCrashAction())
			{
				m_sprites_manager->updateToStage(m_stage_layer);
			}
		}

		virtual void updateBackgroundLayer(CCLayer* bg_layer){};

		virtual void updateWindowsLayer(CCLayer* wnd_layer){};
		
		virtual void drawToBackgroundLayer(CCLayer* bg_layer){};

		virtual void drawToWindowsLayer(CCLayer* wnd_layer){};


	};
};
#endif