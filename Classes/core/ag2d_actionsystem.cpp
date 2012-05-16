#include "..\include\ag2d_actionsystem.h"

using namespace ag2d;

//如果主角与精灵发生动作，由返回true
bool Ag2dActionSystem::validateCrashAction(list<Ag2dSpriteNodeData*> total_sprites)
{
	return true;
}

//发生碰撞的精灵
list<Ag2dSpriteNodeData*> Ag2dActionSystem::getCrashSprites()
{
	list<Ag2dSpriteNodeData*> list;
	return list;
}