#ifndef _A2TH_SPRITESMANAGER_H_
#define _A2TH_SPRITESMANAGER_H_

#include "cocos2d.h"

USING_NS_CC;

namespace ag2d
{
	/******************************************
	 * ���������
	 * ��������ͨ���У��������ݵı仯��������Ϸ�еľ���״̬����������ʧ�����ء������仯�ȣ�
	 *****************************************/
	class Ag2dSpritesManager
	{
	public:
		//////////////////////////////////////////////////////
		//���
		void validate(){};

		void drawToStage(CCLayer* stage_layer){};

		void updateToStage(CCLayer* stage_layer){};
	};
};
#endif