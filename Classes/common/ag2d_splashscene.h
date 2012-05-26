#ifndef _AG2D_SPLASHSCENE_H_
#define _AG2D_SPLASHSCENE_H_

#include <list>
#include <string>
#include "..\include\ag2d_commonscene.h"
using namespace std;
namespace ag2d
{
	class Ag2dSplashListener
	{
	public:
		virtual void onLoading()=0;
		virtual ~Ag2dSplashListener()=0;
	};

	//具备启动界面功能的场景类
	class Ag2dSplashScene : public Ag2dCommonScene
	{
	private:
		//启动界面的图片
		char* m_splash_image;

		//加载过程显示的图片

		char* m_loading_icon;

		//回调接口
		Ag2dSplashListener* m_listener;

	public:
		Ag2dSplashScene(FlowCode code,char* splash);

		//
		void setLoadingListener(Ag2dSplashListener& listener);

		void setLoadingIcon(char* load_icon);

	private:
		
		void splashCallback(CCObject* sender);

		void updateBackgroundLayer(CCLayer& bg_layer);
		void updateWindowsLayer(CCLayer& wnd_layer);
		void drawToBackgroundLayer(CCLayer& bg_layer);
		void drawToWindowsLayer(CCLayer& wnd_layer);
	};
};

#endif