#include "leveldoor.h"
#include "cocos2d.h"
using namespace cocos2d;
void leveldoor::contact_leveldoor()
{
	Director::getInstance()->replaceScene(this->myScene);
}
void leveldoor::bindSpriteAndScene(Sprite* sprite,Scene* scene)
{
	this->mySprite = sprite;
	auto physicsBody3 = PhysicsBody::createBox(this->mySprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	//physicsBody3->setCategoryBitmask(0x04);    
	//physicsBody3->setCollisionBitmask(0x06);
	this->mySprite->setPhysicsBody(physicsBody3);
	this->myScene = scene;
	this->addChild(mySprite);
}