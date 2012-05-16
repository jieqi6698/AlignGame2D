#ifndef _AG2D_LAUNCHER_H_
#define _AG2D_LAUNCHER_H_

#include "ag2d_engine.h"

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

	public:
		static void init();
		static void destory();

		//引擎
		static Ag2dEngine& sharedEngine();

		//精灵管理器
		static Ag2dSpritesManager& sharedSpritesManager();

		//动作系统
		static Ag2dActionSystem* sharedActionSystem();
	};
};

#endif