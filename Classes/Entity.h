#ifndef _Entity_H_
#define _Entity_H_
#include "cocos2d.h"                //�����������ǰ�ͼƬ
USING_NS_CC;
class Entity :public Node
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();               /*��ȡ�������*/
	void bindSprite(Sprite* sprite);     /*�󶨾������*/
protected:
	Sprite* m_sprite;
};
#endif;
