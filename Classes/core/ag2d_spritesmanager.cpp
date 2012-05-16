#include "..\include\ag2d_spritesmanager.h"

using namespace ag2d;

//构造函数
Ag2dSpritesManager::Ag2dSpritesManager()
{

}

//删除一点精灵节点
void Ag2dSpritesManager::removeSprite(int tag)
{
	list<Ag2dSpriteNodeData*>::iterator it;
	for (it = m_total_sprite_data_array.begin(); it != m_total_sprite_data_array.end(); it++)
	{
		Ag2dSpriteNodeData* node = *it;
		if(node->tag == tag){
			m_total_sprite_data_array.remove(node);
			break;
		}
	}
}

//加载初始数据
void Ag2dSpritesManager::load()
{
	srand((unsigned)time(NULL));
	for(int i=0;i<10;i++)
	{
		Ag2dSpriteNodeData* data = new Ag2dSpriteNodeData();
		data->action_file = "action.lua";
		data->is_new = true;
		data->pos_x = rand() % 80  + 400.0f;
		data->pos_y = rand() % 480 + 1.0f;
		data->sprite_file = "menu1.png";
		data->status = SS_NEW;
		data->tag = i;
		data->zOrder = i;
		m_changed_sprite_data_array.push_back(data);
	}
}

//检验
bool Ag2dSpritesManager::validateOnFrame()
{
	return !m_changed_sprite_data_array.empty();
}

//取得全部精灵数据
list<Ag2dSpriteNodeData*> Ag2dSpritesManager::getTotalSpriteArray()
{
	return m_total_sprite_data_array;
}

//取出全部精灵节点
list<Ag2dSpriteNode*> Ag2dSpritesManager::getChangedSpriteArray()
{
	list<Ag2dSpriteNode*> changed_sprite_array;

	for(list<Ag2dSpriteNodeData*>::iterator iter = m_changed_sprite_data_array.begin(); 
		iter != m_changed_sprite_data_array.end(); iter++)
	{
		Ag2dSpriteNode* sprite = new Ag2dSpriteNode();
		Ag2dSpriteNodeData* data = *iter;
		sprite->tag = data->tag;
		sprite->status = data->status;
		if(data->is_new)
		{
			sprite->status = SS_NEW;
			sprite->action = createAction(data->action_file);
			sprite->sprite = createSprite(data->sprite_file);
			sprite->zOrder = data->zOrder;
			sprite->position = ccp(data->pos_x,data->pos_y);
		}
		changed_sprite_array.push_back(sprite);
	}
	return changed_sprite_array;
}

//创建动作
CCFiniteTimeAction* Ag2dSpritesManager::createAction(char* fileName)
{
	return CCMoveBy::actionWithDuration(8, ccp(-800,0) );
}

//创建精灵节点
CCNode* Ag2dSpritesManager::createSprite(char* fileName)
{

	return CCSprite::spriteWithFile(fileName);
}