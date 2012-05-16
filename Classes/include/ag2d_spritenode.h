#ifndef _A2TH_SPRIETNODE_H_
#define _A2TH_SPRIETNODE_H_

#include "cocos2d.h"
#include "ag2d_spritestatus.h"
USING_NS_CC;

namespace ag2d
{
	/******************************************
	 * ����ڵ㡣���ھ������
	 *****************************************/
	
	class Ag2dSpriteNode
	{
	public:
		//����״̬
		Ag2dSpriteStatus status;

		//Ψһ��ʶ
		int tag;

		//����̨���е�z��λ��
		int zOrder;

		//����ڵ�
		CCNode* sprite;

		//���鶯��
		CCFiniteTimeAction* action;

		//��������̨�еĳ�ʼλ��
		CCPoint position;
	};
};

#endif