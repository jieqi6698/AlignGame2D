#ifndef _A2TH_SPRITESMANAGER_H_
#define _A2TH_SPRITESMANAGER_H_

#include "cocos2d.h"

USING_NS_CC;

namespace ag2d
{
	/******************************************
	 * 精灵管理器
	 * 根据数据通道中，精灵数据的变化，管理游戏中的精灵状态（产生，消失、隐藏、动画变化等）
	 *****************************************/
	class Ag2dSpritesManager
	{
	public:
		//////////////////////////////////////////////////////
		//检查
		void validate(){};

		void drawToStage(CCLayer* stage_layer){};

		void updateToStage(CCLayer* stage_layer){};
	};
};
#endif