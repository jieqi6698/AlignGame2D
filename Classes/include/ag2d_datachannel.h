#ifndef _AG2D_DATACHANNEL_H_
#define _AG2D_DATACHANNEL_H_

#include <list>
#include "ag2d_spritenode.h"

using namespace std;

namespace ag2d
{
	
	class Ag2dDataChannel
	{
	private:
		list<Ag2dSpriteNode*> m_sprite_node;

	public:

		list<Ag2dSpriteNode*> loadTotalSprites()
		{
			list<Ag2dSpriteNode*> list;
			for(int i=0;i<10;i++)
			{
				Ag2dSpriteNode* node = new Ag2dSpriteNode(i,450.0f, i * 50.0f);
				node->ResFile = "froggy.png";
				list.push_back(node);
			}
			return list;
		};

	};
};

#endif