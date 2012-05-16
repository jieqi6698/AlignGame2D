#ifndef _A2TH_SCENE_H_
#define _A2TH_SCENE_H_
#include "cocos2d.h"
#include "ag2d_config.h"

USING_NS_CC;
namespace ag2d
{
	/******************************************
	 * 场景
	 * 1、每个场景都具有一个流程码，引擎根据这个流程码来调度场景的切换
	 * 2、场景提供一些通用接口，给引擎调度
	 *****************************************/
	class Ag2dScene : public CCNode
	{
	protected:
		CCScene* m_display_scene;
		float m_measure_width;
		float m_measure_height;
		float m_center_x;
		float m_center_y;

	public:
		//流程码
		FlowCode M_FlowCode;

	public:
		
		//引擎流程被切换到此场景，引擎首先调用此函数对场景进行初始化。此时，场景还没有被显示。
		virtual void initial() = 0;

		////场景被引擎渲染到显示窗口中。
		CCScene* createDisplay();

		//传递场景大小
		void initMeasure(float width,float height);

		//构造函数，必须标识这个场景的流程码
		Ag2dScene(FlowCode code);

		//析构函数
		virtual ~Ag2dScene();

		////场景内所有可显示元素，在此函数中绘制。
		virtual void draw(CCScene* display_scene)=0;

		//在每一帧中回调
		virtual void scheduleOnFrame(ccTime timc)=0;

		//场景已经被引擎调度到显示窗口中显示，此函数被调用
		virtual void didDisplayed()=0;

		//引擎流程被调离此场景，场景即将被销毁，此函数被调用。
		virtual void toDestory()=0;
	};
};

#endif