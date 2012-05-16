#ifndef _AG2D_COMMONSCENE_H_
#define _AG2D_COMMONSCENE_H_

#include "cocos2d.h"
#include "ag2d_launcher.h"
#include "ag2d_scene.h"
USING_NS_CC;

namespace ag2d
{

	class Ag2dCommonScene : public Ag2dScene
	{
	private:
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
		Ag2dActionSystem* m_action_system;
		Ag2dSpritesManager* m_sprites_manager;

	public:
		//�������̱��л����˳������������ȵ��ô˺����Գ������г�ʼ������ʱ��������û�б���ʾ��
		void initial();

		//���캯���������ʶ���������������
		Ag2dCommonScene(FlowCode code);

		//��������
		virtual ~Ag2dCommonScene();

		////���������п���ʾԪ�أ��ڴ˺����л��ơ�
		void draw(CCScene* display_scene);

		//��ÿһ֡�лص�
		void scheduleOnFrame(ccTime timc);

		//�����Ѿ���������ȵ���ʾ��������ʾ���˺���������
		void didDisplayed();

		//�������̱�����˳������������������٣��˺��������á�
		void toDestory();

		//��ʱ�ص�
		void updateCallback(ccTime time);

		void updateStageCallback(ccTime time);

		virtual void updateBackgroundLayer(CCLayer* bg_layer)=0;

		virtual void updateWindowsLayer(CCLayer* wnd_layer)=0;
		
		virtual void drawToBackgroundLayer(CCLayer* bg_layer)=0;

		virtual void drawToWindowsLayer(CCLayer* wnd_layer)=0;


	};
};
#endif