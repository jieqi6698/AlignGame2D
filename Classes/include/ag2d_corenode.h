#ifndef _AG2D_CORENODE_H_
#define _AG2D_CORENODE_H_

#include "ag2d_nodestatus.h"

namespace ag2d
{
	//动作系统根据这个类对象进行计算
	class Ag2dCoreNode
	{
	public:
		Ag2dCoreNode(int tag);
		Ag2dCoreNode(int tag,float x,float y);
		//唯一标识这个节点的值
		int tag;
		//Zorder
		int zOrder;
		//这个节点的状态
		Ag2dNodeStatus status;
		//节点的x坐标
		float pos_x;
		//节点的y坐标
		float pos_y;
	};
};

#endif