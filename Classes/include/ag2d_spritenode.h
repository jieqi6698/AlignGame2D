#ifndef _AG2D_SPRITENODE_H_
#define _AG2D_SPRITENODE_H_

#include "ag2d_corenode.h"
#include "ag2d_spritetype.h"
namespace ag2d
{
	class Ag2dSpriteNode
	{
	public:

		Ag2dSpriteNode(int tag,float x,float y)
			:CoreNode(tag,x,y),
			Type(SPRITE_FILE)
		{};

	public:
		//核心节点数据
		Ag2dCoreNode CoreNode;
		//类型
		Ag2dSpriteType Type;
		//精灵资源文件
		char* ResFile;
		float ResX;
		float ResY;
		float ResWidth;
		float ResHeight;

	};
};
#endif