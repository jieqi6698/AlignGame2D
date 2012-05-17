#ifndef _AG2D_CORENODE_H_
#define _AG2D_CORENODE_H_

#include "ag2d_nodestatus.h"

namespace ag2d
{
	//����ϵͳ��������������м���
	class Ag2dCoreNode
	{
	public:
		Ag2dCoreNode(int tag);
		Ag2dCoreNode(int tag,float x,float y);
		//Ψһ��ʶ����ڵ��ֵ
		int tag;
		//Zorder
		int zOrder;
		//����ڵ��״̬
		Ag2dNodeStatus status;
		//�ڵ��x����
		float pos_x;
		//�ڵ��y����
		float pos_y;
	};
};

#endif