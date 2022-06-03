#include "Entity.h"
Entity::Entity()
{
	m_sprite = NULL;
}
Entity::~Entity(){}
Sprite* Entity::getSprite()
{
	return this->m_sprite;
}
void Entity::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);
	auto physicsBody1 = PhysicsBody::createBox(this->m_Sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody1->setCategoryBitmask(0x01);
	physicsBody1->setCollisionBitmask(0x03);
	this->m_Sprite->setPhysicsBody(physicsBody1)
}
