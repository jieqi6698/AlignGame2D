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
		void initial()
		{
			m_action_system = Ag2dLauncher::sharedActionSystem();
		};

		//���캯���������ʶ���������������
		Ag2dCommonScene(FlowCode code):Ag2dScene(code){};

		//��������
		~Ag2dCommonScene()
		{
		};

		////���������п���ʾԪ�أ��ڴ˺����л��ơ�
		void draw(CCScene* display_scene)
		{
			//�����㶼�������½�Ϊֱ������ϵԭ�㣬
			m_bg_layer = CCLayer::node();
			m_wnd_layer = CCLayer::node();
			//�����㲻���մ�������
			m_bg_layer->setIsTouchEnabled(false);
			drawToBackgroundLayer(m_bg_layer);
			drawToWindowsLayer(m_wnd_layer);
			this->schedule(schedule_selector(Ag2dCommonScene::updateCallback),0.1f);
		};

		//��ÿһ֡�лص�
		void scheduleOnFrame(ccTime timc)
		{
			//���ȶ���ϵͳ���������������
			m_action_system->validate();
			m_sprites_manager->validate();
		};

		//�����Ѿ���������ȵ���ʾ��������ʾ���˺���������
		void didDisplayed()
		{
			m_stage_layer = CCLayer::node();
			m_display_scene->addChild(m_stage_layer,STAGE_LAYER_TAG,STAGE_LAYER_Z_ORDER);
			m_sprites_manager->drawToStage(m_stage_layer);
			this->schedule(schedule_selector(Ag2dCommonScene::updateStageCallback));
		};

		//�������̱�����˳������������������٣��˺��������á�
		void toDestory()
		{
			this->unscheduleAllSelectors();
		};

		//��ʱ�ص�
		void updateCallback(ccTime time)
		{
			updateBackgroundLayer(m_bg_layer);
			updateWindowsLayer(m_wnd_layer);
		};

		void updateStageCallback(ccTime time)
		{
			if(m_action_system->isCrashAction())
			{
				m_sprites_manager->updateToStage(m_stage_layer);
			}
		}

		virtual void updateBackgroundLayer(CCLayer* bg_layer){};

		virtual void updateWindowsLayer(CCLayer* wnd_layer){};
		
		virtual void drawToBackgroundLayer(CCLayer* bg_layer){};

		virtual void drawToWindowsLayer(CCLayer* wnd_layer){};


	};
};
#endif