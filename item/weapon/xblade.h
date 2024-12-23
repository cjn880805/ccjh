//xblade.h 血刀
//Lanwood 2001-02-07

EQUIP_BEGIN(CIxblade);

//under, we will custom our item

virtual void create(int nFlag = 0)	
{
	set_name("血刀", "blood blade");
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "blade");			//set the skill applied
	set_weight(1000);

	set("unit", "把");
	set("long", "这是一把缠在腰间的宝刀，刀锋带着淡淡的血影。");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回刀鞘。");
	
	set("apply/damage", 20);
};

//设置装备修正值
int Do_Action(int nAct, CChar * me)
{
	int ret = 0;

	//判断有否主人
	if(! environment()->is_character()) return 0;
	me = (CChar *)environment();

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED)) 
	{
		//如果用血刀技能，伤害力增加
		if (me->query_skill("xue_dao", 1)
		&& ! DIFFERSTR(me->query_skill_mapped("blade"), "xue_dao" ) && me->query_skill("longxiang", 1)
		&& ! DIFFERSTR(me->query_skill_mapped("force"), "longxiang" ) )
		{
			set("apply/damage",400);
			set("power", 1);
		}

		ret = Do_Wield();
		if(! query("equipped") && query("power")) 
		{			
			set("apply/damage", 20);
			del("power");
		}

		return ret;
	}
	
	if(nAct == DO_UNWIELD)
	{
		ret = Do_UnWield();

		if(! query("equipped") && query("power"))
		{
			set("apply/damage", 20);
			del("power");
		}

		return ret;
	}

	return CItem::Do_Action(nAct, me);
}

EQUIP_END;




