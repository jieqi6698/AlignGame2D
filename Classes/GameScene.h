
#include "include\ag2d_commonscene.h"

using namespace ag2d;

class GameScene : public Ag2dCommonScene
{
public:
	GameScene(FlowCode code):Ag2dCommonScene(code)
	{
		
	};

	void updateBackgroundLayer(CCLayer& bg_layer)
	{
		
	};

	void updateWindowsLayer(CCLayer& wnd_layer)
	{
		
	};
		
	void drawToBackgroundLayer(CCLayer& bg_layer)
	{
		CCSprite* bg = CCSprite::spriteWithFile("background.jpg");
		bg->setPosition(ccp(m_center_x,m_center_y));
		bg_layer.addChild(bg);
	};

	void drawToWindowsLayer(CCLayer& wnd_layer)
	{
		
	};

};