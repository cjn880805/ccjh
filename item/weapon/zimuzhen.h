//zimuzhen.h

//Sample for ITEM: 子母飞针
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CIzimuzhen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "子母飞针");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set_weight(20000);		//set item weight

	set("long", "这是一根细若柔丝的银针。");
	set("unit", "些");
	set("value", 3500);
	set("base_value", 1);
	set("material", "steel");
	set("base_unit", "根");
	set("base_weight", 10); 
	set_amount(80);
//	init_throwing(50);
	set("apply/damage", 50);					//set the modifiers of attribute

};
/*************************
void init()
{
        add_action("do_wield", "wield");
	add_action("do_unwield", "unwield");
}
// 30
int do_wield(string arg)

{  object victim; int damage_bonus; int factor;
       object me=this_player();

        object ob;
        string str;
	int i, count;

// 40
        if (!id(arg))   return notify_fail("你要装备什么？\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");

// 50
	if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
              message_vision(str, me, ob);
			  me->set_temp("marks/子母针",1);
 
//	}

              return 1;
	}

        else
                return 0;
}
int do_unwield(string arg)

{  object victim; int damage_bonus; int factor;
       object me=this_player();

        object ob;
        string str;
	int i, count;

// 40
        if (!id(arg))   return notify_fail("你要放下什么？\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经放下了。\n");

// 50
	if( ob->unwield() ) {
              if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
              message_vision(str, me, ob);
			  me->delete_temp("marks/子母针");

//	}

              return 1;
	}

        else
                return 0;
}**************************/

AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



