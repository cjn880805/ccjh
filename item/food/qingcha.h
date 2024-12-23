//qingcha.h

//Sample for ITEM 清茶
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIqingcha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "清茶");	//set item name

	set_weight(50); 

	set("long", "一杯热茶，悠悠地冒着香气～～～");
	set("unit", "杯");
	set("value", 1000);
	set("remaining", 2);
	set("drink_supply", 25);

};
virtual int do_use(CChar * me, CContainer * target)
{
	int  recover, hp, e_hp, m_hp;
	recover = 5;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。");

//	if( me->query("water") >=  me->max_water_capacity() )
//		return notify_fail("你已经喝太多了，再也灌不下一滴水了。");
	
	set("value", 0l);
	me->add("water", query("drink_supply"));
	hp = me->query("hp");
	e_hp = me->query("eff_hp");
	m_hp = me->query("max_hp");
	
	// No heal effect for 香茶
	if (hp < e_hp )
	{
		if ( (hp + recover) >= e_hp )
		{
			me->set("hp", e_hp);
		} else
		{
			me->set("hp", hp+recover);
		}
	}
	
	if( me->is_fighting() ) 
		me->start_busy(2);
	
	add("remaining", -1);
	if ( query("remaining") )
	{
		message_vision("$N端起杯清茶，有滋有味地品了几口。\n一种清爽的感觉直入心脾，$N觉得精神好多了。", me);
	} 
	else
	{
		message_vision("$N端起镂花小杯，把剩下的清茶一饮而尽。\n真是沁人心脾，$N觉得精神好多了。", me);
		destruct(this);
	}
	return 1;
}
/************

int do_drink(string arg)
{

        int heal, recover, jing, e_jing, m_jing;

        recover = 5;

        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
            return notify_fail("你上一个动作还没有完成。\n");
        if( this_player()->query("water") >=
            this_player()->max_water_capacity() )
            return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

        set("value", 0l);
        this_player()->add("water", query("drink_supply"));
        jing = this_player()->query("hp");
        e_jing = this_player()->query("eff_jing");
        m_jing = this_player()->query("max_jing");

// No heal effect for 香茶
         if (jing < e_jing )
        {
            if ( (jing + recover) >= e_jing )
            {
                this_player()->set("hp", e_jing);
            } else
            {
                this_player()->set("hp", jing+recover);
            }
        }

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        add("remaining", -1);
        if ( query("remaining") )
        {
                 message_vision("$N端起杯清茶，有滋有味地品了几口。\n"+
                "一种清爽的感觉直入心脾，$N觉得精神好多了。\n", this_player());
        } else
        {
                 message_vision("$N端起镂花小杯，把剩下的清茶一饮而尽。\n"+
                "真是沁人心脾，$N觉得精神好多了。\n", this_player());
                destruct(this_object());
        }
        return 1;
}

************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp