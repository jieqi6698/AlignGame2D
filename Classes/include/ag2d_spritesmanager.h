#ifndef _A2TH_SPRITESMANAGER_H_
#define _A2TH_SPRITESMANAGER_H_

#include "cocos2d.h"
#include "ag2d_spritetype.h"
USING_NS_CC;

namespace ag2d
{
	/******************************************
	 * 精灵管理器
	 * 根据数据通道中，精灵数据的变化，管理游戏中的精灵状态（产生，消失、隐藏、动画变化等）
	 *****************************************/
	class Ag2dSpritesManager
	{
	private:
		CCMutableArray<CCSprite*> * m_sprites_cache;

	public:
		
		Ag2dSpritesManager();
		~Ag2dSpritesManager();
		/*
			将数据通道中的精灵绘制到舞台中。这个函数被调用一次。
		*/
		void drawToStage(CCLayer* stage_layer);

		/*
			将数据通道中的精灵更新，这个函数被定时调用
		*/
		void updateToStage(CCLayer* stage_layer);

		//根据精灵种类创建精灵
		CCSprite* createSprite(char* resFile,Ag2dSpriteType type);
	};
};
#endif