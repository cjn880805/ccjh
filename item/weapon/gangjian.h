EQUIP_BEGIN(CIGangJian);

virtual void create(int nFlag = 0)		
{
	set_name( "钢剑");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied

	set_weight(6000);		//set item weight

	set("unit", "柄");
	set("long", "这是一柄精工制成的钢剑，这种剑在将领之间非常流行。");
	set("value", 400);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回剑鞘。");

	set("apply/damage", 20);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp