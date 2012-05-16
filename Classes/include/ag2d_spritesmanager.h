#ifndef _A2TH_SPRITESMANAGER_H_
#define _A2TH_SPRITESMANAGER_H_

#include <list>
#include "ag2d_spritenode.h"
#include "ag2d_spritenodedata.h"

namespace ag2d
{
	/******************************************
	 * 精灵管理器
	 * 根据数据通道中，精灵数据的变化，管理游戏中的精灵状态（产生，消失、隐藏、动画变化等）
	 *****************************************/
	class Ag2dSpritesManager
	{
	private:
		list<Ag2dSpriteNodeData*> m_changed_sprite_data_array;
		list<Ag2dSpriteNodeData*> m_total_sprite_data_array;

	private:
		//创建动作
		CCFiniteTimeAction* createAction(char* fileName);
		//创建精灵节点
		CCNode* createSprite(char* fileName);

	public:
		//构造函数
		Ag2dSpritesManager();

		//这个函数在游戏的每一帧中被调用，用于检验游戏精灵数据是否发生变化。
		//这种变化是指精灵与主角发生关系而产生的变化。
		bool validateOnFrame();

		//加载初始数据
		void load();

		//删除一点精灵节点
		void removeSprite(int tag);

		//取出状态发生变化的精灵组
		list<Ag2dSpriteNode*> getChangedSpriteArray();

		//取得全部精灵数据
		list<Ag2dSpriteNodeData*> getTotalSpriteArray();

		//////////////////////////////////////////////////////
		//检查
		void validate(){};

		void drawToStage(CCLayer* stage_layer){};

		void updateToStage(CCLayer* stage_layer){};
	};
};
#endif