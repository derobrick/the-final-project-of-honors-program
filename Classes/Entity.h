#ifndef _Entity_H_
#define _Entity_H_
#include "cocos2d.h"                //基础，作用是绑定图片
USING_NS_CC;
class Entity :public Node
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();               /*获取精灵对象*/
	void bindSprite(Sprite* sprite);     /*绑定精灵对象*/
protected:
	Sprite* m_sprite;
};
#endif;
