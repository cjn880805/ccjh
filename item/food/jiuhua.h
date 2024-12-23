//jiuhua.h

//Sample for ITEM 九花玉露丸
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIjiuhua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "九花玉露丸");	//set item name

	set("unit", "颗");
	set("long", "这是一颗晶莹碧绿的九花玉露丸，经桃花岛主精心练制，有起死回生之功。");
	set("value", 5000);

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。");
	
	me->set("eff_hp",me->query("max_hp"));
	me->set("hp",me->query("max_hp"));
	me->set("mp",me->query("max_mp"));
	message_vision("$N吃下一颗九花玉露丸，一股清新凉爽从丹田升起，向全身扩散！",me);
	me->start_busy(1);
	destruct(this);
	return 1;
	
}
virtual int Can_Use()
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp