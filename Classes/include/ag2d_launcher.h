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
		//����
		static Ag2dEngine* m_engine;
		//���������
		static Ag2dSpritesManager* m_sprites_manager;
		//����ϵͳ
		static Ag2dActionSystem* m_action_system;
		//����ͨ��
		static Ag2dDataChannel* m_data_channel;

	public:
		//�Ը���ģ����г�ʼ��
		static void init();

		//����ģ������
		static void destory();

		// * ����һ����������ã�����һ�����󸱱���

		//����
		static Ag2dEngine& sharedEngine();

		//���������
		static Ag2dSpritesManager& sharedSpritesManager();

		//����ϵͳ
		static Ag2dActionSystem& sharedActionSystem();

		//����ͨ��
		static Ag2dDataChannel& sharedDataChannel();
	};
};

#endif