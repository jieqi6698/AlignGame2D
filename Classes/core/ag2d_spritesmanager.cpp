#include "..\include\ag2d_spritesmanager.h"
#include <list>
#include "..\include\ag2d_spritenode.h"
#include "..\include\ag2d_launcher.h"

using namespace ag2d;

Ag2dSpritesManager::Ag2dSpritesManager()
{
	m_sprites_cache = new CCMutableArray<CCSprite*>;
}

Ag2dSpritesManager::~Ag2dSpritesManager()
{
	delete m_sprites_cache;
}

void Ag2dSpritesManager::drawToStage(CCLayer& stage_layer)
{
	//从数据通道中取出新创建的精灵数据，把它绘制到舞台中
	list<Ag2dSpriteNode*>& target_array = Ag2dLauncher::sharedDataChannel().loadTotalSprites();
	list<Ag2dSpriteNode*>::iterator it;
	for (it = target_array.begin(); it != target_array.end(); it++)
	{
		Ag2dSpriteNode* node = *it;
		CCSprite* sprite = createSprite(node->ResFile,node->Type);
		sprite->setPosition(ccp(node->CoreNode.pos_x,node->CoreNode.pos_y));
		sprite->setTag(node->CoreNode.tag);
		m_sprites_cache->addObject(sprite);
		stage_layer.addChild(sprite,node->CoreNode.zOrder);
	}//end for
}

CCSprite* Ag2dSpritesManager::createSprite(char* resFile,Ag2dSpriteType type)
{
	CCSprite* sprite = NULL;
	switch(type)
	{
		case SPRITE_FILE:
			sprite = CCSprite::spriteWithFile(resFile);
			break;
		case SPRITE_BATCH:
			sprite = CCSprite::spriteWithFile(resFile);
			break;
		case SPRITE_FRAME:
			sprite = CCSprite::spriteWithFile(resFile);
			break;
	}
	return sprite;
}

void Ag2dSpritesManager::updateToStage(CCLayer& stage_layer)
{
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	for (it = m_sprites_cache->begin(); it != m_sprites_cache->end(); it++)
	{
		CCSprite* sprite = *it;
		float x = sprite->getPositionX();
		float y = sprite->getPositionY();
		x += -1;
		//y += -1;
		sprite->setPosition(ccp(x,y));
	}
}