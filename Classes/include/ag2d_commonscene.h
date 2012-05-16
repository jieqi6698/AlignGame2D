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
		void initial();

		//构造函数，必须标识这个场景的流程码
		Ag2dCommonScene(FlowCode code);

		//析构函数
		virtual ~Ag2dCommonScene();

		////场景内所有可显示元素，在此函数中绘制。
		void draw(CCScene* display_scene);

		//在每一帧中回调
		void scheduleOnFrame(ccTime timc);

		//场景已经被引擎调度到显示窗口中显示，此函数被调用
		void didDisplayed();

		//引擎流程被调离此场景，场景即将被销毁，此函数被调用。
		void toDestory();

		//定时回调
		void updateCallback(ccTime time);

		void updateStageCallback(ccTime time);

		virtual void updateBackgroundLayer(CCLayer* bg_layer)=0;

		virtual void updateWindowsLayer(CCLayer* wnd_layer)=0;
		
		virtual void drawToBackgroundLayer(CCLayer* bg_layer)=0;

		virtual void drawToWindowsLayer(CCLayer* wnd_layer)=0;


	};
};
#endif