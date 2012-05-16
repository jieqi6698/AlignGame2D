#ifndef _A2TH_SPRITENODEDATA_H_
#define _A2TH_SPRITENODEDATA_H_

#include "ag2d_spritestatus.h"

namespace ag2d
{
	class Ag2dSpriteNodeData
	{
	public:
		//����״̬
		Ag2dSpriteStatus status;
		//Ψһ��ʶ
		int tag;
		//����̨���е�z��λ��
		int zOrder;
		//��ʼλ��
		float pos_x;
		float pos_y;
		//�Ƿ�Ϊ�½�����
		bool is_new;

		char* action_file;
		char* sprite_file;
	};

};
#endif