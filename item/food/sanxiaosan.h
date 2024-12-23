//sanxiaosan.h

//Sample for ITEM 三笑逍遥散
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIsanxiaosan);

//under, we will custom our item

void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "三笑逍遥散");	//set item name

	set("long", "一包无色的粉末, 看样子不是寻常物品. ");
	set("unit", "包");
	set("pour_type", "sanxiao_poison");
	set("value", 20000);
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("unit", "些");

	set("material", "iron");
	set("wield_msg", "$N屏息静气，托出一包三笑逍遥散来！");
	set("unwield_msg","$N小心翼翼地将手里的三笑逍遥散放进怀里。");
	set_amount(1);
	
	set("apply/damage", 1);					//set the modifiers of attribute

};

const char * hit_ob(CChar *me, CChar *target, LONG damage)
{
	if(me->query_skill("poison",1) < 250 &&
		 ( me->query_skill("force", 1) > target->query_skill("force")) ) 
	{
			target->apply_condition("sanxiao_poison", target->query_condition("sanxiao_poison") + 3);
			return 0;
	}
	
	me->apply_condition("sanxiao_poison", me->query_condition("sanxiao_poison") + 3);
	
	return 0;
}	

int do_use(CChar * me, CContainer * target)
{
	message_vision("$N仰头咽下一包$n", me, this);
	me->die();
	destruct(this);
	return 1;

}
/****************
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	if(arg=="san" || arg=="xiaoyao san")
	{
		message_vision("$N仰头咽下一包" + name() + "。\n", me);
		this_player()->die();
		destruct(this_object());
	}
	return 1;
}
***************/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp