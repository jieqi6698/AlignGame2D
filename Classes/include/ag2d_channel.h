#ifndef _A2TH_CHANNEL_H_
#define _A2TH_CHANNEL_H_

#include "ag2d_sceneconf.h"
namespace ag2d
{

	/******************************************
	 * ���ݴ���ͨ����ʵ����һ�����ݻ�����/��ת����������Ϸ��������
	 * 1����������
	 * 2����������
	 * 3��ȫ�ֹ���
	 * 4�������Ƿ�����ϵ�Ĺ����ʶ��
	 *****************************************/
	class Ag2dDataChannel
	{
	public:
		//��ǰ���������ݶ���
		Ag2dSceneConf* m_running_scene_conf;

	public:
		Ag2dDataChannel()
		{
			m_running_scene_conf = new Ag2dSceneConf();
		};

	};
};

#endif