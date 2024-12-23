//jiuping.h

//Sample for ITEM 酒瓶
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIjiuping);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "一缸壮阳酒");	//set item name

	set_weight(700);
	
	set("long", "一个碎花细瓷的小缸，装了熏熏醉人的壮阳酒。");
	set("unit", "个");
	set("value", 200);
	set("max_liquid", 15);
	set("liquid/type", "alcohol");
	set("liquid/name", "壮阳酒");
	set("liquid/remaining", 15);
	set("liquid/drunk_supply", 3);
	set("m_exppoint",random(300));
	set("no_get",1);
	set("no_give",1);
	set("no_drop",1);

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
//	CContainer * me = Environment();
	if (target != me)
		return notify_fail("酒只能自己喝。");

	char msg[255];

	int i;

	i=query("m_exppoint");

	if(!i)
	{
		tell_object(me,"你把酒往嘴里一倒：哗～～～光了。");
		destruct(this);
		return 1;
	}

	if(!random(4))
	{
		me->add("combat_exp", i);
		snprintf(msg, 255, "$N将酒慢慢品味，越品越有味道……\n$N从饮酒中得到了%d点经验！", i);
		message_vision(msg,me);
		me->FlushMyInfo();
		
	}
	else
	{
		snprintf(msg, 255, "$N咕嘟咕嘟的把酒喝下。\n$N的脸色一阵红一阵白，好象是喝醉了！", i);
		message_vision(msg,me);
		me->apply_condition("drunk", 20 + random(20));
		me->FlushMyInfo();

	}

	destruct(this);

	return 1;
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp