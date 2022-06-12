# 项目魔塔

## 实现功能

实现基本游戏功能，玩家通过按键控制移动，碰到障碍物停止

有简单框架支撑，设计合理，使用封装、继承、多态

UI显示玩家信息数据，角色属性系统，多种怪物类型

地图系统，道具系统，商店系统，标准回合制战斗，场景切换系统

## 各文件具体内容

### 主角类

	void Player::Move(EventKeyboard::KeyCode keyCode, Event* event) 
	{
		switch (keyCode) 
		{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
		{
			cocos2d::Size spriteSize = m_sprite->getContentSize();
			if (setTagPosition(Pos.x - spriteSize.width, Pos.y)) {		
				auto moveBy = MoveBy::create(0.2f, Vec2(-m_sprite->getContentSize().width, 0));
				m_sprite->runAction(Sequence::create(moveBy, nullptr));
				action(4);
				Pos.x -= m_sprite->getContentSize().width;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_D:
	{
		cocos2d::Size spriteSize = m_sprite->getContentSize();
		if (setTagPosition(Pos.x + spriteSize.width, Pos.y)) {
			auto moveBy = MoveBy::create(0.2f, Vec2(m_sprite->getContentSize().width, 0));
			m_sprite->runAction(Sequence::create(moveBy, nullptr));
			action(8);
			Pos.x += m_sprite->getContentSize().width;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	case EventKeyboard::KeyCode::KEY_W:
	{
		cocos2d::Size spriteSize = m_sprite->getContentSize();
		if (setTagPosition(Pos.x, Pos.y + spriteSize.height)) {
			auto moveBy = MoveBy::create(0.2f, Vec2(0, m_sprite->getContentSize().height));
			m_sprite->runAction(Sequence::create(moveBy, nullptr));
			action(12);
			Pos.y += m_sprite->getContentSize().height;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_S:
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		cocos2d::Size spriteSize = m_sprite->getContentSize();
		if (setTagPosition(Pos.x, Pos.y - spriteSize.height)) {
			auto moveBy = MoveBy::create(0.2f, Vec2(0, -m_sprite->getContentSize().height));
			m_sprite->runAction(Sequence::create(moveBy, nullptr));
			action(0);
			Pos.y -= m_sprite->getContentSize().height;
		}
		break;
	}
	default:
		break;
	}
	}
	void Player::setTiledMap(cocos2d::TMXTiledMap* map,cocos2d::Point Pos) {
		this->mymap = map;
		this->Pos = Pos;
		this->wall = mymap->getLayer("wall");
		this->monster = mymap->getLayer("monster");
		this->key = mymap->getLayer("key");
		this->SAM = mymap->getLayer("SAM");
		this->door = mymap->getLayer("door");
	}
	bool Player::setTagPosition(float x, float y) {
	cocos2d::Point dstPos = cocos2d::Point(x, y);
	/*获取主角当前的格子*/
	cocos2d::Point tiledPos = tileCoordForPostion(cocos2d::Point(dstPos.x, dstPos.y));
	/*获取地图上的标识*/
	int walltiledGid = wall->getTileGIDAt(tiledPos);
	int monstertiledGid = monster->getTileGIDAt(tiledPos);
	int keytiledGid = key->getTileGIDAt(tiledPos);
	int SAMtiledGid = SAM->getTileGIDAt(tiledPos);
	int doortiledGid = door->getTileGIDAt(tiledPos);
	if (walltiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(walltiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Collidable") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Collidable");
			if (prop.asString().compare("1") == 0) {
				return false;
			}
		}
	}
	if (monstertiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(monstertiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Gaintone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Gaintone");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Gaintone* mymonster = Gaintone::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */
	
				return false;
			}
		}
		if (propertiesMap.find("Gainttwo") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Gainttwo");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Gainttwo* mymonster = Gainttwo::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */
				return false;
			}
		}
		if (propertiesMap.find("Commonone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Commonone");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Commonone* mymonster = Commonone::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */
				return false;
			}
		}
		if (propertiesMap.find("Commontwo") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Commontwo");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Commontwo* mymonster = Commontwo::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */
				return false;
			}
		}
	}
	if (keytiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(keytiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("YellowKey") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("YellowKey");
			if (prop.asString().compare("1") == 0) {
				/*获得黄钥匙*/
				this->Get_YellowKey();
				/*          */
				key->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("BlueKey") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("BlueKey");
			if (prop.asString().compare("1") == 0) {
				/*获得蓝钥匙*/
				this->Get_BlueKey();
				/*          */
				key->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("RedKey") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("RedKey");
			if (prop.asString().compare("1") == 0) {
				/*获得红钥匙*/
				this->Get_RedKey();
				key->removeTileAt(tiledPos);
				return false;
			}
		}
	}
	if (SAMtiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(SAMtiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("redmedicine") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("redmedicine");
			if (prop.asString().compare("1") == 0) {
				/*获得红色血瓶*/
				this->Get_Hp(500);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("bluemedicine") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("bluemedicine");
			if (prop.asString().compare("1") == 0) {
				/*获得蓝色血瓶*/
				this->Get_Hp(1000);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("redstone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("redstone");
			if (prop.asString().compare("1") == 0) {
				/*获得红色宝石*/
				this->Get_Att(20);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("bluestone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("bluestone");
			if (prop.asString().compare("1") == 0) {
				/*获得蓝色宝石*/
				this->Get_Def(20);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
	}
	if (doortiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(doortiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("YellowDoor") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("YellowDoor");
			if (prop.asString().compare("1") == 0) {
				/*遇到黄色门*/
				if (this->Look_YellowKey() > 0)
				{
					this->Use_YellowKey();
					door->removeTileAt(tiledPos);
				}
				/*          */
				return false;
			}
		}
		if (propertiesMap.find("BlueDoor") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("BlueDoor");
			if (prop.asString().compare("1") == 0) {
				/*遇到蓝色门*/
				if (this->Look_BlueKey() > 0)
				{
					this->Use_BlueKey();
					door->removeTileAt(tiledPos);
				}
				/*          */
				return false;
			}
		}
		if (propertiesMap.find("RedDoor") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("RedDoor");
			if (prop.asString().compare("1") == 0) {
				/*遇到红色门*/
				if (this->Look_RedKey() > 0)
				{
					door->removeTileAt(tiledPos);
					this->Use_RedKey();
				}
				/*          */
				return false;
			}
		}
		if (propertiesMap.find("StairsDown") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("StairsDown");
			if (prop.asString().compare("1") == 0) {
				/*遇到向下的楼梯*/
	
				/*          */
				door->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("StairsUp") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("StairsUp");
			if (prop.asString().compare("1") == 0) {
				/*遇到向上的楼梯*/
				this->Get_stair();
				/*          */
				door->removeTileAt(tiledPos);
				return false;
			}
		}
	}
	return true;
	}
### 怪物类

	bool Boss::getSuck()
	{
		if (isTriggle(suckRate))
		{
			return (this->m_Attack * 0.5);
		}
		return false;
	}
	
	bool Boss::getCrit()
	{
		if (isTriggle(critRate))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool Boss::isTriggle(int rate)
	{
		//通过isTriggle判断是否触发特效
		//随机一个1-100的数字
		//srand( (unsigned)time(NULL) )
		srand(time(0));
		int num = rand() % 100 + 1;
		if (num < rate)
			return true;
		else
			return false;
	}
	
	void Boss::Attack(Player* player)
	{
		int addHp = 0;
		bool isCrit = false;
		//计算吸血
		addHp = this->getSuck();
		//计算暴击
		isCrit = this->getCrit();
		if (isCrit)//触发了暴击效果，造成双倍伤害
		{
			m_Attack *= 2;
		}
		if (addHp > 0)//触发了吸血效果，增加血量
		{
	}
	//计算真实伤害
	int TrueDamage = (this->m_Attack - player->Look_Def()) > 0 ? (this->m_Attack - player->Look_Def()) : 1;
	player->Get_Hp(-TrueDamage);
	this->m_Hp += addHp;
	}
### 地图

```
cocos2d::Scene* map2::createScene() {
	auto scene = map2::create();
	return scene;
}
bool map2::init() {
	if (!cocos2d::Scene::initWithPhysics()) {
		return false;
	}
	if (!cocos2d::Scene::init()) {
		return false;
	}
	Floor2 floor2;
	cocos2d::TMXTiledMap* map_2 = floor2.getMap();
	myplayer = floor2.getPlayer();
	auto* layer = TollgateDataLayer::create();
	this->addChild(layer, 50);
	layer->bind(myplayer);
	this->addChild(map_2);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto map3 = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(map2::map3_trans, this));
	auto map3_label = Label::createWithSystemFont("第三关", "微软雅黑", 12);
	map3_label->setPosition(visibleSize.width - 100, visibleSize.height / 11 * 8);
	map3->setPosition(visibleSize.width - 40, visibleSize.height / 11 * 8);
	addChild(map3_label);
	auto map1 = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(map2::map1_trans, this));
	auto map1_label = Label::createWithSystemFont("第一关", "微软雅黑", 12);
	map1_label->setPosition(visibleSize.width - 100, visibleSize.height / 11 * 10);
	map1->setPosition(visibleSize.width - 40, visibleSize.height / 11 * 10);
	addChild(map1_label);
	auto map_trans_menu = Menu::create(map3,map1, NULL);
	map_trans_menu->setPosition(Vec2::ZERO);
	this->addChild(map_trans_menu);
	return true;
}
void map2::map3_trans(Ref* pSender)
{
	if (this->myplayer->Look_stair() >= 2)
	{
		auto next = map3::createScene();
		Director::getInstance()->pushScene(next);
	}
}
void map2::map1_trans(Ref* pSender)
{
	if (this->myplayer->Look_stair() >= 1)
	{
		Director::getInstance()->popScene();
	}
}

```

### 道具

```
bool shopscene::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto AtkBuy = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::buy_Atk, this));
    auto AtkBuy_label = Label::createWithSystemFont("购买攻击力", "微软雅黑", 12);              //攻击力购买的标签和按钮
    AtkBuy->setPosition(visibleSize.width / 4 * 3 - 60, visibleSize.height / 8 * 7);
    AtkBuy_label->setPosition(visibleSize.width / 4 * 3, visibleSize.height / 8 * 7);
    this->addChild(AtkBuy_label);
    auto DefBuy = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::buy_Def, this));
    auto DefBuy_label = Label::createWithSystemFont("购买防御力", "微软雅黑", 12);              // 防御力购买的标签和按钮
    DefBuy->setPosition(visibleSize.width / 4 * 3 - 60, visibleSize.height / 8 * 6);
    DefBuy_label->setPosition(visibleSize.width / 4 * 3, visibleSize.height / 8 * 6);
    this->addChild(DefBuy_label);
    auto HpBuy = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::buy_Hp, this));
    auto HpBuy_label = Label::createWithSystemFont("购买血量", "微软雅黑", 12);                 //血量购买的标签和按钮
    HpBuy->setPosition(visibleSize.width / 4 * 3 - 60, visibleSize.height / 8 * 5);
    HpBuy_label->setPosition(visibleSize.width / 4 * 3, visibleSize.height / 8 * 5);
    this->addChild(HpBuy_label);
    auto RankBuy = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::buy_Rank, this));
    auto RankBuy_label = Label::createWithSystemFont("购买等级", "微软雅黑", 12);              //等级购买的标签和按钮
    RankBuy->setPosition(visibleSize.width / 4 * 3 - 60, visibleSize.height / 8 * 4);
    RankBuy_label->setPosition(visibleSize.width / 4 * 3, visibleSize.height / 8 * 4);
    this->addChild(RankBuy_label);
    auto BlueKeyBuy = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::buy_BlueKey, this));
    auto BlueKeyBuy_label = Label::createWithSystemFont("购买蓝色钥匙", "微软雅黑", 12);          //蓝色钥匙购买的标签和按钮
    BlueKeyBuy->setPosition(visibleSize.width / 4 * 3 - 60, visibleSize.height / 8 * 3);
    BlueKeyBuy_label->setPosition(visibleSize.width / 4 * 3, visibleSize.height / 8 * 3);
    this->addChild(BlueKeyBuy_label);
    auto RedKeyBuy = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::buy_RedKey, this));
    auto RedKeyBuy_label = Label::createWithSystemFont("购买红色钥匙", "微软雅黑", 12);           //红色钥匙购买的标签和按钮
    RedKeyBuy->setPosition(visibleSize.width / 4 * 3 - 60, visibleSize.height / 8 * 2);
    RedKeyBuy_label->setPosition(visibleSize.width / 4 * 3, visibleSize.height / 8 * 2);
    this->addChild(RedKeyBuy_label);
    auto YellowKeyBuy = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::buy_YellowKey, this));
    auto YellowKeyBuy_label = Label::createWithSystemFont("购买黄色钥匙", "微软雅黑", 12);         //黄色钥匙购买的标签和按钮
    YellowKeyBuy->setPosition(visibleSize.width / 4 * 3 - 60, visibleSize.height / 8 * 1);
    YellowKeyBuy_label->setPosition(visibleSize.width / 4 * 3, visibleSize.height / 8 * 1);
    this->addChild(YellowKeyBuy_label);
    auto ShopClose = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(shopscene::close_shop, this));
    auto ShopClose_label = Label::createWithSystemFont("关闭商店", "微软雅黑", 12);               // 关闭商店的标签和按钮
    ShopClose->setPosition(visibleSize.width - 20, visibleSize.height - 20);
    this->addChild(ShopClose_label);
    auto shopmenu = Menu::create(AtkBuy, DefBuy, HpBuy, BlueKeyBuy, RedKeyBuy, YellowKeyBuy, RankBuy, ShopClose, NULL);
    shopmenu->setPosition(Vec2::ZERO);
    this->addChild(shopmenu, 1);
    return true;
}
```



## 未实现的功能

战斗显示等