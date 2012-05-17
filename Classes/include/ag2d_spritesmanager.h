#ifndef _A2TH_SPRITESMANAGER_H_
#define _A2TH_SPRITESMANAGER_H_

#include "cocos2d.h"
#include "ag2d_spritetype.h"
USING_NS_CC;

namespace ag2d
{
	/******************************************
	 * ���������
	 * ��������ͨ���У��������ݵı仯��������Ϸ�еľ���״̬����������ʧ�����ء������仯�ȣ�
	 *****************************************/
	class Ag2dSpritesManager
	{
	private:
		CCMutableArray<CCSprite*> * m_sprites_cache;

	public:
		
		Ag2dSpritesManager();
		~Ag2dSpritesManager();
		/*
			������ͨ���еľ�����Ƶ���̨�С��������������һ�Ρ�
		*/
		void drawToStage(CCLayer* stage_layer);

		/*
			������ͨ���еľ�����£������������ʱ����
		*/
		void updateToStage(CCLayer* stage_layer);

		//���ݾ������ഴ������
		CCSprite* createSprite(char* resFile,Ag2dSpriteType type);
	};
};
#endif