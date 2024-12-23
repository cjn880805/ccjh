EQUIP_BEGIN(CIGangZhang);

void create(int nFlag = 0)	
{
	set_name("钢杖", "gang zhang");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "staff");		
	set_weight(5000);	

	set("unit", "根");
	set("long", "这是一根粗重的钢杖。");
	set("value", 1500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N抽出一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回腰间。");

	set("apply/damage", 25);
};



EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp