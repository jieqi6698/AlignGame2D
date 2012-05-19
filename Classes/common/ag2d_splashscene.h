#ifndef _AG2D_SPLASHSCENE_H_
#define _AG2D_SPLASHSCENE_H_

#include <list>
#include <string>
#include "..\include\ag2d_commonscene.h"
using namespace std;
namespace ag2d
{
	
	class Ag2dSplashScene : public Ag2dCommonScene
	{
	private:
		list<char*> * m_splash_list;
		int m_splash_index;

	public:
		Ag2dSplashScene(FlowCode code);

		void setSplashRes(char* splash);

		void splashCallback(ccTime timc);
	private:
		void updateBackgroundLayer(CCLayer& bg_layer);

		void updateWindowsLayer(CCLayer& wnd_layer);
		
		void drawToBackgroundLayer(CCLayer& bg_layer);

		void drawToWindowsLayer(CCLayer& wnd_layer);
	};
};

#endif