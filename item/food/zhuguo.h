//zhuguo.h

//Sample for ITEM 朱果
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzhuguo);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "朱果");	//set item name

	set_weight(20);

	set("unit", "颗");
	set("long","这是一颗朱果，通体鲜红，一望而知是不可多得的珍品。");
	set("value", 1000);

//	set("no_get", "嘿嘿，做梦吧! ");
//	set("no_drop","朱果你都想扔？");
	
};
virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	if(!me->query_temp("pro/z_hp") && !me->query_temp("pro/hp")&& !me->query_temp("pro5/hp"))
	{
		me->set("max_hp", me->query_temp("max_hp")*2);
		me->set("hp", me->query_temp("max_hp")*2);
		me->set("eff_hp", me->query_temp("max_hp")*2);
		me->set_temp("pro/hp",1);
		me->UpdateMe();
	}
	else if(me->query_temp("pro/hp"))
	{
		me->set("max_hp", me->query_temp("max_hp")/2);
		me->set("hp", me->query_temp("max_hp")/2);
		me->set("eff_hp", me->query_temp("max_hp")/2);
		me->delete_temp("pro/hp");
		me->UpdateMe();
	}
	snprintf(msg, 255, "%s吃下一颗朱果，只觉饥渴全消，一股暖流从丹田直冲上来。", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp