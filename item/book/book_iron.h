//book_iron.h

//Sample for ITEM: 铁手掌
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbook_iron);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁手掌");	//set item name

 	set_weight(2000);		//set item weight

	set("unit", "块");
	set("long", "易筋经攻防篇:这是一块铁手掌，上面凹凹凸凸刻满了人形搏击的场面。");
	set("value", 500);
	set("material", "steel");
	set("skill/name","parry");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",10);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",29);	// the maximum level you can learn
	set("skill/min_skill",0l);  // the maximum level you can learn
	set("apply/armor", 3 );

};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
		return do_study(me);

	return 0;
}

int do_study(CChar *me)
{
 	if ( me->is_fighting() 
	&& me->query_skill("parry", 1) >= 30 
	&& me->query_skill("parry", 1) <= 100 )
	{
		me->receive_damage("hp", 20);
		me->improve_skill("parry", me->query("int"));
		message_vision("$N一边战斗，一边抽空急急忙忙地拿出铁手掌仔细研究。", me);
		return 1;
	}

	return 0;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp