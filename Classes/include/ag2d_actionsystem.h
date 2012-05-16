#ifndef _AG2D_ACTIONSYSTEM_H_
#define _AG2D_ACTIONSYSTEM_H_

#include <list>
#include "ag2d_spritenodedata.h"
using namespace std;
namespace ag2d
{
	class Ag2dActionSystem
	{
	public:
		//如果主角与精灵发生动作，由返回true
		bool validateCrashAction(list<Ag2dSpriteNodeData*> total_sprites);

		//发生碰撞的精灵
		list<Ag2dSpriteNodeData*> getCrashSprites();

		///////////////////////////////////////////////
		void validate(){};
		//是否发生动作
		bool isCrashAction(){};
	};
};

#endif