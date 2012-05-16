#ifndef _A2TH_GAME_H_
#define _A2TH_GAME_H_

#include "ag2d_scene.h"
#include "ag2d_channel.h"
#include "ag2d_spritesmanager.h"
#include "ag2d_actionsystem.h"

namespace ag2d
{
	/******************************************
	 * 实际用于游戏发开的“游戏”场景
	 * 1、分三层：窗口层、精灵层、背景层
	 * 2、包括界面管理、数据通道、数据处理中心、动作系统、精灵管理等模块
	 * 3、提供全局的数据通道
	 *****************************************/
	class Ag2dGameScene : public Ag2dScene
	{
	private:
		//精灵管理器定时间隔。如果设置为0，则在每一帧中都检测。
		float m_sprites_manager_duration;
		//默认背景
		char* m_background;

	protected:

		//当前场景对象引用
		CCScene* m_display_scene;
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
		

	private:
		//定时器需要的中间回调函数，用于调用drawSpritesToStage函数
		void scheduleCallSpriteManager(ccTime time);
		//定时器回调窗口层的刷新操作
		void scheduleCallRefreshWindowsLayer(ccTime time);
		//定时器回调背景层的刷新操作
		void scheduleCallRefreshBackgroundLayer(ccTime time);
		//定时器回舞台层的检测操作
		void scheduleCallActionSystem(ccTime time);

		//从精灵管理器中绘制到舞台
		void drawSpritesToStage(CCLayer* stage_layer);

	public:

		//构造函数，必须标识这个场景的流程码
		Ag2dGameScene(FlowCode code);

		//析构函数
		virtual ~Ag2dGameScene();

		//场景内所有可显示元素，在此函数中绘制。
		void draw(CCScene* display_scene);

		//初始化数据通道
		void initial();

		//舞台层在被显示后才绘制
		void didDisplayed();

		//清除定时器
		void toDestory();

		//在背景层上绘制
		virtual void drawToBackgroundLayer(CCLayer* bg_layer){};

		//刷新背景层。在此函数中检测背景参数，如果变化则更新界面。
		virtual void updateBackgroundLayer(CCLayer* bg_layer){};

		//在窗口层上绘制
		virtual void drawToWindowsLayer(CCLayer* wnd_layer){};

		//刷新窗口层.在此函数中检测窗口参数，如果变化则更新界面。
		virtual void updateWindowsLayer(CCLayer* wnd_layer){};

	};
};
#endif