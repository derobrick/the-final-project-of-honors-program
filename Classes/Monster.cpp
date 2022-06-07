#include "Monster.h"
Monster::Monster()
{
	m_sprite = 0;
}
Monster::~Monster() {}
Sprite* Monster::getSprite()
{
	return this->m_sprite;
}
void Monster::bindSprite(Sprite* sprite)
{
	this->mySprite = sprite;
	this->addChild(mySprite);
	auto physicsBody6 = PhysicsBody::createBox(this->mySprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody6->setCategoryBitmask(0x07);
	physicsBody6->setCollisionBitmask(0x09);
	this->mySprite->setPhysicsBody(physicsBody6);
}

