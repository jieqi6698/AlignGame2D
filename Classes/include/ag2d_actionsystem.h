#ifndef _AG2D_ACTIONSYSTEM_H_
#define _AG2D_ACTIONSYSTEM_H_

#include <list>
#include "ag2d_spritenodedata.h"
using namespace std;
namespace ag2d
{
	class Ag2dActionSystem
	{
	public:
		//��������뾫�鷢���������ɷ���true
		bool validateCrashAction(list<Ag2dSpriteNodeData*> total_sprites);

		//������ײ�ľ���
		list<Ag2dSpriteNodeData*> getCrashSprites();

		///////////////////////////////////////////////
		void validate(){};
		//�Ƿ�������
		bool isCrashAction(){};
	};
};

#endif