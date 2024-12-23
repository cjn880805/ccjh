//putizi.h

//Sample for ITEM 菩提子
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIputizi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "菩提子");	//set item name

	set("unit", "颗");
	set("long", "这是一颗晶莹如玉的菩提子，采自灵山佛祖座前，珍稀无比，乃万年菩提树之实，功能化百劫，渡千灾，与天地同寿。");
	set("value", 1000000);

};

virtual int do_use(CChar * me, CContainer * target)
{
	int mp_limit, hp_limit, mp_skill, add_skill, improve;

	mp_limit = me->query_skill("mp")*10;
	hp_limit = me->query("max_hp");
	mp_skill = me->query_skill("mp", 1);
	
	if ( hp_limit <= mp_limit  )
	{
		improve = mp_limit - hp_limit;

		if ( improve < 100 )
		{ 
			add_skill = mp_skill + (100 - improve)/5 + 1;
			me->set_skill("mp", add_skill );
		}
	}
	
	me->add("max_hp", 100);
	me->add("hp", 100);

	message_vision( "$N吃下一颗菩提子，顿然间只觉一股浩荡无比的真气直冲顶门..." , me);
	me->unconcious();
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp