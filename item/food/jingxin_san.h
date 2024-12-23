//jingxin_san.h

//Sample for ITEM 静心口服液
//coded by Cat
//data: 2001-4-3

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjingxin_san);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "静心口服液");	//set item name
	set("long", "女人中年要静心，李清照入魔多年才悟出这个道理。");
	set("unit", "瓶");
	set("value", 2000);
};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N喝下一瓶$n", me,this);

	if (me->query("condition/bingpo_poison") > 0) 
	{
		me->apply_condition("bingpo_poison", 0);
		message_vision("$N觉得心情平静了不少，冰魄银针的毒性慢慢退去。", me);
	}
	if (me->query("condition/wuduz_poison") > 0) 
	{
		me->apply_condition("wuduz_poison", 0);
		message_vision("$N觉得心情平静了不少，五毒神掌的毒性慢慢退去。", me);
	}
	else
		message_vision("$N觉得心情平静了不少，由衷的说道：“女人中年要静心，静心口服液。”", me);

    me->receive_healing("hp", 40);
	me->FlushMyInfo();
	destruct(this);
    return 1;
}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp