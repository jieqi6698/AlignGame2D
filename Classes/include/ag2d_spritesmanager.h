#ifndef _A2TH_SPRITESMANAGER_H_
#define _A2TH_SPRITESMANAGER_H_

#include <list>
#include "ag2d_spritenode.h"
#include "ag2d_spritenodedata.h"

namespace ag2d
{
	/******************************************
	 * ���������
	 * ��������ͨ���У��������ݵı仯��������Ϸ�еľ���״̬����������ʧ�����ء������仯�ȣ�
	 *****************************************/
	class Ag2dSpritesManager
	{
	private:
		list<Ag2dSpriteNodeData*> m_changed_sprite_data_array;
		list<Ag2dSpriteNodeData*> m_total_sprite_data_array;

	private:
		//��������
		CCFiniteTimeAction* createAction(char* fileName);
		//��������ڵ�
		CCNode* createSprite(char* fileName);

	public:
		//���캯��
		Ag2dSpritesManager();

		//�����������Ϸ��ÿһ֡�б����ã����ڼ�����Ϸ���������Ƿ����仯��
		//���ֱ仯��ָ���������Ƿ�����ϵ�������ı仯��
		bool validateOnFrame();

		//���س�ʼ����
		void load();

		//ɾ��һ�㾫��ڵ�
		void removeSprite(int tag);

		//ȡ��״̬�����仯�ľ�����
		list<Ag2dSpriteNode*> getChangedSpriteArray();

		//ȡ��ȫ����������
		list<Ag2dSpriteNodeData*> getTotalSpriteArray();

		//////////////////////////////////////////////////////
		//���
		void validate(){};

		void drawToStage(CCLayer* stage_layer){};

		void updateToStage(CCLayer* stage_layer){};
	};
};
#endif