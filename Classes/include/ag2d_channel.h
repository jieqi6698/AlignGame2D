#ifndef _A2TH_CHANNEL_H_
#define _A2TH_CHANNEL_H_

#include "ag2d_sceneconf.h"
namespace ag2d
{

	/******************************************
	 * 数据传递通道。实质是一个数据缓存器/中转器，保存游戏所有数据
	 * 1、主角数据
	 * 2、道具数据
	 * 3、全局怪物
	 * 4、与主角发生关系的怪物标识集
	 *****************************************/
	class Ag2dDataChannel
	{
	public:
		//当前场景的数据对象
		Ag2dSceneConf* m_running_scene_conf;

	public:
		Ag2dDataChannel()
		{
			m_running_scene_conf = new Ag2dSceneConf();
		};

	};
};

#endif