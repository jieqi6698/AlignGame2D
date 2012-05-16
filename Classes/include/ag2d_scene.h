#ifndef _A2TH_SCENE_H_
#define _A2TH_SCENE_H_
#include "cocos2d.h"
#include "ag2d_config.h"

USING_NS_CC;
namespace ag2d
{
	/******************************************
	 * ����
	 * 1��ÿ������������һ�������룬���������������������ȳ������л�
	 * 2�������ṩһЩͨ�ýӿڣ����������
	 *****************************************/
	class Ag2dScene : public CCNode
	{
	protected:
		CCScene* m_display_scene;
		float m_measure_width;
		float m_measure_height;
		float m_center_x;
		float m_center_y;

	public:
		//������
		FlowCode M_FlowCode;

	public:
		
		//�������̱��л����˳������������ȵ��ô˺����Գ������г�ʼ������ʱ��������û�б���ʾ��
		virtual void initial() = 0;

		////������������Ⱦ����ʾ�����С�
		CCScene* createDisplay();

		//���ݳ�����С
		void initMeasure(float width,float height);

		//���캯���������ʶ���������������
		Ag2dScene(FlowCode code);

		//��������
		virtual ~Ag2dScene();

		////���������п���ʾԪ�أ��ڴ˺����л��ơ�
		virtual void draw(CCScene* display_scene)=0;

		//��ÿһ֡�лص�
		virtual void scheduleOnFrame(ccTime timc)=0;

		//�����Ѿ���������ȵ���ʾ��������ʾ���˺���������
		virtual void didDisplayed()=0;

		//�������̱�����˳������������������٣��˺��������á�
		virtual void toDestory()=0;
	};
};

#endif