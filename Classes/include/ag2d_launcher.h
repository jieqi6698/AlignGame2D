#ifndef _AG2D_LAUNCHER_H_
#define _AG2D_LAUNCHER_H_

#include "ag2d_engine.h"

namespace ag2d
{
	class Ag2dLauncher
	{
	private:
		//����
		static Ag2dEngine* m_engine;
		//���������
		static Ag2dSpritesManager* m_sprites_manager;
		//����ϵͳ
		static Ag2dActionSystem* m_action_system;

	public:
		static void init();
		static void destory();

		//����
		static Ag2dEngine& sharedEngine();

		//���������
		static Ag2dSpritesManager& sharedSpritesManager();

		//����ϵͳ
		static Ag2dActionSystem* sharedActionSystem();
	};
};

#endif