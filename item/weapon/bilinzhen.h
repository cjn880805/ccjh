//bilinzhen.h

//Sample for ITEM: 碧磷针
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIbilinzhen);

//under, we will custom our item

void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "碧磷针");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("unit", "些");
	set("value", 0l);
	set("base_unit", "枚");
	set("base_weight", 300);
	set("base_value", 0l);
	set("material", "iron");
	set("long", "碧磷针是星宿派淬毒暗器，针长寸许，发出诡异的光。");
	set("wield_msg", "$N迅速地从身上摸出一些碧磷针，捏在手中就待发出！");
	set("unwield_msg","$N将手里剩下的碧磷针一抖就不见了。");
	set_amount(50);
	
	set("apply/damage", 50);					//set the modifiers of attribute
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG damage)
{
	if(me->query_skill("huagong_dafa",1) > 30)
		victim->apply_condition("xx_poison", 10);
	return 0;
}	
//设置装备修正值
int Do_Action(int nAct, CChar * me)
{
	//判断有否主人
	if(! environment()->is_character()) return 0;
	int ret = 0;

	me = (CChar *)environment();

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED)) 
	{
		//如果用血刀技能，伤害力增加
		if (me->query_skill("poison")
              && ! DIFFERSTR(me->query_skill_mapped("force"), "huagong_dafa" ))
		{
			add("apply/damage",100);
			set("power", 1);
		}

		ret = Do_Wield();
		if(! ret && query("power")) 
		{			
			add("apply/damage", -100);
			del("power");
		}

		return ret;
	}
	
	if(nAct == DO_UNWIELD)
	{
		ret = Do_UnWield();

		if(ret && query("power"))
		{
			add("apply/damage", -100);
			del("power");
		}

		return ret;
	}

	return CItem::Do_Action(nAct, me);
}

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp