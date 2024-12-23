//renshenguo.h

//Sample for ITEM 人参果
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIrenshenguo);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "人参果");	//set item name

	set("unit", "朵");
	set("long", "这是一只人参果, 已经成型, 真的象极了三周不满的小孩。");

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->add("max_mp",10);
	me->set("eff_hp",me->query("max_hp"));
	me->set("eff_mp",me->query("max_mp"));
	me->set("hp",me->query("max_hp"));
	me->set("mp",me->query("max_mp"));
	message_vision("$N吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，甚至不再感到饥饿干渴!",me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp