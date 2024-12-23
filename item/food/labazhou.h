//laba_zhou.h

//Sample for ITEM 腊八粥
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIlaba_zhou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "腊八粥");	//set item name
	
	set("unit", "碗");
	set("long", "这是一碗热粥，其中蒸气上冒，兀自有一个个气泡从粥底冲将上来，一碗粥尽作深绿之色，看上去说不出的诡异。闻着药气刺鼻，其毒可知。");
	set("value", 50000);
  
};

virtual int do_use(CChar * me, CContainer * target)
{
	
	if ( me->query_temp("num" ) > 0 )
	{
		me->add_temp("num", 1);
		me->add("max_mp", -100);
		message_vision( "$N又喝下一碗腊八粥，只觉得肝肠寸断，五脏欲裂，原来喝得太急太多，药效适得其反！" , me);
	}
	
	else
	{
		me->add("max_mp", 100);
		me->add("mp", 100);
		message_vision( "$N喝下一碗腊八粥，顿然间只觉一股浩荡无比的真气直冲顶门..." , me);
		me->set_temp("num", 1);
	}
	
	me->unconcious();
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp