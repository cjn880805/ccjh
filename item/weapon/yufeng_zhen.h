//yufeng_zhen.h

//Sample for ITEM: 玉蜂针
//coded by cat
//data: 2001-4-2

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIyufeng_zhen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "玉蜂针");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("unit", "束");
	set("value", 0l);
	set("base_unit", "支");
	set("base_weight", 300);
	set("base_value", 0l);
	set("material", "iron");
	set("long", "龙儿采玉蜂毒炼成的暗器。");
	set("wield_msg", "$N轻轻地拿出一把玉蜂针捏在手里");
	set("unwield_msg","$N将手里剩下的玉蜂针轻巧地别在衣襟上。");
	set_amount(20);
	set("apply/damage", 50);					//set the modifiers of attribute
	
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG damage)
{
	if(me->query_skill("yunv_xinfa",1) < 30)
		return 0;
	victim->apply_condition("yufeng_poison", 10);
	return 0;
}

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp