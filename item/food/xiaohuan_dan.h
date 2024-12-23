//xiaohuan_dan.h

//Sample for ITEM 小还丹
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxiaohuan_dan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "小还丹");	//set item name

	set("unit", "颗");
	set("long", "这是一颗莹白溜圆的小还丹。此丹乃少林奇药，助长内力，灵效无比。");
	set("value", 10000);
	set("no_drop", "这样东西不能离开你。");
	set("shaolin",1);

};
virtual int do_use(CChar * me, CContainer * target)
{
    if ( me->query("mp") >= me->query("max_hp") * 2 )
	{
		 tell_object(me, "你现在没必要吃小还丹。");
		 return 0;
	}

	if( me->is_busy() )
	{
		tell_object(me, "别急，慢慢吃，小心别噎着了。");
		return 0;
	}

	me->start_busy(2);
	if ( DIFFERSTR(me->query_skill_mapped("force"), "hunyuan_yiqi" ))
	{
		me->set("mp", 0l);
		message_vision("$N吃下一颗小还丹，只觉得五脏欲裂，原来所练内功不符，反而大损修为！", me);
		destruct(this);
		return 1;
	}

	if ( me->query("condition/bonze_drug") > 0 )
	{
		me->add("mp", -200);
		message_vision("$N吃下一颗小还丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！", me);
	}
	else
	{
		me->add("mp", 200);
		message_vision("$N吃下一颗小还丹，只觉得身轻如燕，四肢百骸真气充盈无比，几欲奔腾而出！", me);
	}

	me->apply_condition("bonze_drug", 30);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp