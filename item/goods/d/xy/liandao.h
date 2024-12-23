//liandao.h 逍遥任务特殊道具

EQUIP_BEGIN(CIliandao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("镰刀", "liao dao");
	
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "柄");
	set("long", "这是一柄很普通的镰刀。");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回裤腰。");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;




