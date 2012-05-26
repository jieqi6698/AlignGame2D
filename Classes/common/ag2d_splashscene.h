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

	//�߱��������湦�ܵĳ�����
	class Ag2dSplashScene : public Ag2dCommonScene
	{
	private:
		//���������ͼƬ
		char* m_splash_image;

		//���ع�����ʾ��ͼƬ

		char* m_loading_icon;

		//�ص��ӿ�
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