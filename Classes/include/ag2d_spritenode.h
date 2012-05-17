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
		//���Ľڵ�����
		Ag2dCoreNode CoreNode;
		//����
		Ag2dSpriteType Type;
		//������Դ�ļ�
		char* ResFile;
		float ResX;
		float ResY;
		float ResWidth;
		float ResHeight;

	};
};
#endif