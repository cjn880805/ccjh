//xuedao.h

//Sample for ITEM: 血刀
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIxuedao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "血刀");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(1000);		//set item weight

	set("unit", "把");
	set("long",  "这是一把缠在腰间的宝刀，刀锋带着淡淡的血影。"  );
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回刀鞘。");
// 	init_blade(20);
	set("apply/damage", 60);					//set the modifiers of attribute

};
/************************
int do_wield(string arg)
{
        object me=this_player();

        object ob;
        string str;
	int i, count;

        if (!id(arg))   return notify_fail("你要装备什么？\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");


	if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
              message_vision(str, me, ob);
              if ( me->query_skill("xue-dao")
              && me->query_skill_mapped("blade") == "xue-dao" )
			me->add_temp("apply/damage",200);

              return 1;
	}

        else
                return 0;
}
int do_unwield(string arg)
{
        object me=this_player();
	object ob, *inv;
	string str;
	int i;

	if( !arg ) return notify_fail("你要脱掉什么？\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if(  ob->query("equipped")!="wielded" )
		return notify_fail("你并没有装备这样东西作为武器。\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
		message_vision(str, me, ob);
		if ( me->query_skill("xue-dao")
			&& me->query_skill_mapped("blade") == "xue-dao" )
			me->add_temp("apply/damage", -380);

		return 1;
	} else
		return 0;
}


********************/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp