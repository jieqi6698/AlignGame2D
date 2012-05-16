#ifndef _A2TH_SPRITENODEDATA_H_
#define _A2TH_SPRITENODEDATA_H_

#include "ag2d_spritestatus.h"

namespace ag2d
{
	class Ag2dSpriteNodeData
	{
	public:
		//精灵状态
		Ag2dSpriteStatus status;
		//唯一标识
		int tag;
		//在舞台层中的z轴位置
		int zOrder;
		//起始位置
		float pos_x;
		float pos_y;
		//是否为新建精灵
		bool is_new;

		char* action_file;
		char* sprite_file;
	};

};
#endif