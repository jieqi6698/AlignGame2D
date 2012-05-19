#ifndef _AG2D_LAUNCHER_H_
#define _AG2D_LAUNCHER_H_

#include "ag2d_engine.h"
#include "ag2d_spritesmanager.h"
#include "ag2d_actionsystem.h"
#include "ag2d_datachannel.h"

namespace ag2d
{
	
	class Ag2dLauncher
	{
	private:
		//引擎
		static Ag2dEngine* m_engine;
		//精灵管理器
		static Ag2dSpritesManager* m_sprites_manager;
		//动作系统
		static Ag2dActionSystem* m_action_system;
		//数据通道
		static Ag2dDataChannel* m_data_channel;

	public:
		//对各个模块进行初始化
		static void init();

		//销毁模块数据
		static void destory();

		// * 返回一个对象的引用，而非一个对象副本。

		//引擎
		static Ag2dEngine& sharedEngine();

		//精灵管理器
		static Ag2dSpritesManager& sharedSpritesManager();

		//动作系统
		static Ag2dActionSystem& sharedActionSystem();

		//数据通道
		static Ag2dDataChannel& sharedDataChannel();
	};
};

#endif