#ifndef _A2TH_SPRIETNODE_H_
#define _A2TH_SPRIETNODE_H_

#include "cocos2d.h"
#include "ag2d_spritestatus.h"
USING_NS_CC;

namespace ag2d
{
	/******************************************
	 * 精灵节点。用于精灵管理
	 *****************************************/
	
	class Ag2dSpriteNode
	{
	public:
		//精灵状态
		Ag2dSpriteStatus status;

		//唯一标识
		int tag;

		//在舞台层中的z轴位置
		int zOrder;

		//精灵节点
		CCNode* sprite;

		//精灵动作
		CCFiniteTimeAction* action;

		//精灵在舞台中的初始位置
		CCPoint position;
	};
};

#endif