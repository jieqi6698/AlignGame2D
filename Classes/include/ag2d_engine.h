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
	 * 引擎
	 *****************************************/
	class Ag2dEngine
	{
	private:
		//当前运行的场景
		Ag2dScene* m_running_scene;

		//For test
		Ag2dScene* reg_scene;

	public:

		Ag2dEngine();

		//创建OpenEL窗口。在其它平台上这个函数不需要处理。这里主要用于Win32平台下创建OpenEL窗口。
		bool init();

		//启动引擎。对导演Director类进行初始化
		void start();

		//暂停引擎
		void pause();

		//恢复引擎
		void resume();

		//停止引擎
		void end();

		////////////////////////////// 引擎提供的功能接口 //////////////////////////////

		//改变场景流程。这个动作会使场景发生变换
		void changeSceneFlow(FlowCode code);

		//注册场景
		void registerScene(Ag2dScene* scene);

		//播放场景
		void playScene(Ag2dScene* scene);
	};
};

#endif