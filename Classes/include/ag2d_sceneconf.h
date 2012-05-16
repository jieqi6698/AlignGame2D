#ifndef _AG2D_SCENECONF_H_
#define _AG2D_SCENECONF_H_

namespace ag2d
{
	//当前场景的数据对象
	class Ag2dSceneConf
	{
	public:
		char* background;

	public:
		Ag2dSceneConf():background("background.jpg")
		{
		};	
	};
};
#endif