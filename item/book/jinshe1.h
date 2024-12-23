//jinshe1.h

//Sample for ITEM: 「金蛇秘芨」上册
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIjinshe1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "「金蛇秘芨」上册");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "本");
	set("long", "这是一本用薄纸写成的书。上书：「金蛇秘芨」。书皮泛黄，看来已经保存很久了。");
	set("material", "paper");

	set("no_drop", "这样东西不能离开你。");
	set("no_get", "这样东西不能离开那儿。");
	set("no_put", "这样东西不能放在那儿。");

 
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "du") == 0)
		return do_du(me);
	return 0;
}

int do_du(CChar *me )
{
	CContainer * where ;
	int pxlevel; 
	int neili_lost;
	where = me->environment();
	
	if (where->query("pigging"))
	{
		tell_object(me,"你还是专心拱猪吧！");
		return 1;
	}
	if (me->is_busy()) 
	{
		tell_object(me,"你现在正忙着呢。");
		return 1;
	}
	if( me->is_fighting() )
	{
		tell_object(me,"你无法在战斗中专心下来研读新知！");
		return 1;
	}
	if( !me->query_skill("literate", 1) )
	{
		tell_object(me,"你是个文盲，先学点文化(literate)吧。");
		return 1;
	}

	set("book_verb", "du");

	char msg[255];
	tell_room(me->environment(), snprintf(msg, 255, "%s正专心地研读金蛇密芨。", me->name()), me);
	
	if( me->query("hp") < 15 ) 
	{
		tell_object(me,"你现在过于疲倦，无法专心下来研读新知。");
		return 1;
	}
	neili_lost = 5;
	if( me->query("mp") < neili_lost) 
	{
		tell_object(me,"你内力不够，无法钻研这么高深的武功。");
		return 1;
	}
	pxlevel = me->query_skill("jinshe_jian", 1);
	if( CChar::level2skill(me->query("level")) < pxlevel) 
	{
		tell_object(me,"你的等级不够，再怎么读也没用。");
		return 1;
	}
//	if( me->query_skill("jinshe_jian", 1) < 50)
//	{
//		tell_object(me,"你研读了一会儿，但是发现上面所说的对你而言都太深奥了，没有学到任何东西。");
//		return 1;
//	}
	if( me->query_skill("jinshe_jian", 1) > 199)
	{
		tell_object(me,"你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。");
		return 1;
	}
	me->receive_damage("hp", 15);
	me->set("mp",me->query("mp")-neili_lost);
	me->improve_skill("jinshe_jian", me->query_skill("literate", 1)/3+1);
	tell_object(me,"你研读金蛇密芨，颇有心得。");
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp