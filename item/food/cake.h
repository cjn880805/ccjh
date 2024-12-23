//cake.h

//Sample for ITEM 蛋糕
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIcake);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{

	 static char xunbuname[7][13]={"法式蛋糕","三层如意蛋糕","大蛋糕","飞天彩绘蛋糕","纯奶油蛋糕","樱桃蛋糕","结婚蛋糕"};

	 set_name(xunbuname[random(7)]);
	 
	set_weight(200);
	
	set("long", "一个看来很诱人的蛋糕。");
	set("unit","块");
	set("value",0l);
	set("no_get",1);
	set("no_give",1);
	set("no_drop",1);
//	set("food_remaining",4);
	set("m_exppoint",random(200));
	
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
//	CContainer * me = Environment();
	if (target != me)
		return notify_fail("蛋糕只能自己吃。");

	char msg[255];

	if(! me || ! me->Query(IS_CHAR)) return 0;	//正再生
	int i;

	i=query("m_exppoint");

	if(!i)
	{
		tell_object(me,"你把蛋糕三口两口啃了个精光");
		destruct(this);
		return 0;
	}

	if(!random(3))
	{
		me->add("combat_exp", i);
		snprintf(msg, 255, "$N拿起蛋糕，慢慢的舔了舔，咂咂嘴，开始细心品尝。\n$N从蛋糕中发现了%d点经验！", i);
		message_vision(msg,me);
		me->FlushMyInfo();		
	}
	else
	{
		snprintf(msg, 255, "$N拿起蛋糕，慢慢的舔了舔，终于忍不住两三口吃光。\n$N的肚子中突然传来爆炸的声音！！", i);
		message_vision(msg,me);
		me->receive_damage("hp", 50 + i);
		me->FlushMyInfo();

	}

		destruct(this);

	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp