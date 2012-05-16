#ifndef _A2TH_ENGINE_H_
#define _A2TH_ENGINE_H_

#include "SimpleAudioEngine.h"
#include "CCScriptSupport.h"
#include "CCLuaEngine.h"

#include "ag2d_scene.h"
#include "ag2d_spritesmanager.h"
#include "ag2d_actionsystem.h"

using namespace CocosDenshion;

namespace ag2d
{
	/******************************************
	 * ����
	 *****************************************/
	class Ag2dEngine
	{
	private:
		//��ǰ���еĳ���
		Ag2dScene* m_running_scene;

		//For test
		Ag2dScene* reg_scene;

	public:

		Ag2dEngine();

		//����OpenEL���ڡ�������ƽ̨�������������Ҫ����������Ҫ����Win32ƽ̨�´���OpenEL���ڡ�
		bool init();

		//�������档�Ե���Director����г�ʼ��
		void start();

		//��ͣ����
		void pause();

		//�ָ�����
		void resume();

		//ֹͣ����
		void end();

		////////////////////////////// �����ṩ�Ĺ��ܽӿ� //////////////////////////////

		//�ı䳡�����̡����������ʹ���������任
		void changeSceneFlow(FlowCode code);

		//ע�᳡��
		void registerScene(Ag2dScene* scene);

		//���ų���
		void playScene(Ag2dScene* scene);
	};
};

#endif