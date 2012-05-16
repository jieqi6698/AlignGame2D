#include "AppDelegate.h"

#include "cocos2d.h"

#include "CCEGLView.h"

#include "include\ag2d_launcher.h"
#include "GameScene.h"

USING_NS_CC;
using namespace ag2d;

AppDelegate::AppDelegate()
{
	//��������ʼ��
	Ag2dLauncher::init();
	//ע�᳡��
	Ag2dLauncher::sharedEngine().registerScene(new GameScene(99));;
}

AppDelegate::~AppDelegate()
{
	//��������
	Ag2dLauncher::sharedEngine().end();
}

bool AppDelegate::initInstance()
{
	//��ʼ������
	return Ag2dLauncher::sharedEngine().init();
}

bool AppDelegate::applicationDidFinishLaunching()
{
	//��ʼ������
	Ag2dLauncher::sharedEngine().start();
	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
	//��ͣ
	Ag2dLauncher::sharedEngine().pause();
}

void AppDelegate::applicationWillEnterForeground()
{
	//�ָ�
    Ag2dLauncher::sharedEngine().resume();
}
