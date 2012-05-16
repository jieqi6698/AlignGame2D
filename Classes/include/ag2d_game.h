#ifndef _A2TH_GAME_H_
#define _A2TH_GAME_H_

#include "ag2d_scene.h"
#include "ag2d_channel.h"
#include "ag2d_spritesmanager.h"
#include "ag2d_actionsystem.h"

namespace ag2d
{
	/******************************************
	 * ʵ��������Ϸ�����ġ���Ϸ������
	 * 1�������㣺���ڲ㡢����㡢������
	 * 2�����������������ͨ�������ݴ������ġ�����ϵͳ����������ģ��
	 * 3���ṩȫ�ֵ�����ͨ��
	 *****************************************/
	class Ag2dGameScene : public Ag2dScene
	{
	private:
		//�����������ʱ������������Ϊ0������ÿһ֡�ж���⡣
		float m_sprites_manager_duration;
		//Ĭ�ϱ���
		char* m_background;

	protected:

		//��ǰ������������
		CCScene* m_display_scene;
		//���������ָ��
		CCLayer* m_bg_layer;
		//���ڲ����ָ��
		CCLayer* m_wnd_layer;
		//������̨��
		CCLayer* m_stage_layer;

		//�������ʶ
		static const int BG_LAYER_TAG = 0xA06E0;
		//������Z-Order
		static const int BG_LAYER_Z_ORDER = 0;

		//��̨���ʶ
		static const int STAGE_LAYER_TAG = 0xA06E1;
		//��̨��Z-Order
		static const int STAGE_LAYER_Z_ORDER = 1;

		//���ڲ��ʶ
		static const int WINDOWS_LAYER_TAG = 0xA06E2;
		//���ڲ�Z-Order
		static const int WINDOWS_LAYER_Z_ORDER = 2;

	protected:
		

	private:
		//��ʱ����Ҫ���м�ص����������ڵ���drawSpritesToStage����
		void scheduleCallSpriteManager(ccTime time);
		//��ʱ���ص����ڲ��ˢ�²���
		void scheduleCallRefreshWindowsLayer(ccTime time);
		//��ʱ���ص��������ˢ�²���
		void scheduleCallRefreshBackgroundLayer(ccTime time);
		//��ʱ������̨��ļ�����
		void scheduleCallActionSystem(ccTime time);

		//�Ӿ���������л��Ƶ���̨
		void drawSpritesToStage(CCLayer* stage_layer);

	public:

		//���캯���������ʶ���������������
		Ag2dGameScene(FlowCode code);

		//��������
		virtual ~Ag2dGameScene();

		//���������п���ʾԪ�أ��ڴ˺����л��ơ�
		void draw(CCScene* display_scene);

		//��ʼ������ͨ��
		void initial();

		//��̨���ڱ���ʾ��Ż���
		void didDisplayed();

		//�����ʱ��
		void toDestory();

		//�ڱ������ϻ���
		virtual void drawToBackgroundLayer(CCLayer* bg_layer){};

		//ˢ�±����㡣�ڴ˺����м�ⱳ������������仯����½��档
		virtual void updateBackgroundLayer(CCLayer* bg_layer){};

		//�ڴ��ڲ��ϻ���
		virtual void drawToWindowsLayer(CCLayer* wnd_layer){};

		//ˢ�´��ڲ�.�ڴ˺����м�ⴰ�ڲ���������仯����½��档
		virtual void updateWindowsLayer(CCLayer* wnd_layer){};

	};
};
#endif