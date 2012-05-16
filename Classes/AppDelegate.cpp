#include "AppDelegate.h"

#include "cocos2d.h"

#include "CCEGLView.h"

#include "include\ag2d_launcher.h"
#include "GameScene.h"

USING_NS_CC;
using namespace ag2d;

AppDelegate::AppDelegate()
{
	//启动器初始化
	Ag2dLauncher::init();
	//注册场景
	Ag2dLauncher::sharedEngine().registerScene(new GameScene(99));;
}

AppDelegate::~AppDelegate()
{
	//结束引擎
	Ag2dLauncher::sharedEngine().end();
}

bool AppDelegate::initInstance()
{
	//初始化引擎
	return Ag2dLauncher::sharedEngine().init();
}

bool AppDelegate::applicationDidFinishLaunching()
{
	//初始化启动
	Ag2dLauncher::sharedEngine().start();
	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
	//暂停
	Ag2dLauncher::sharedEngine().pause();
}

void AppDelegate::applicationWillEnterForeground()
{
	//恢复
    Ag2dLauncher::sharedEngine().resume();
}
