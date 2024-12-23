//shedangao.h

//Sample for ITEM 蛇胆膏
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshedangao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "蛇胆膏");	//set item name

	set("unit", "块");
	set("long", "这是珍贵补品『蛇胆膏』。");
	set("value", 100);

};
virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("max_hp")>=600)
	{
		tell_object(me,"你吃『蛇胆膏』已无效用！");
		return 0;
	}
	if(me->query("max_hp")<400)
	{
		me->add("max_hp", 2);
		me->add("eff_hp", 2);
		me->add("hp",4);
	}
	else
	{
		me->add("max_hp",1);
		me->add("eff_hp", 1);
		me->add("hp",2);
	}
	message_vision( "$N吃下一块蛇胆膏，顿觉一股浩荡真气直涌上来，精气大增..." , me);
	destruct(this);
	return 1;

}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp