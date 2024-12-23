//axe.h

EQUIP_BEGIN(CIaxe);

//under, we will custom our item

virtual void create(int nFlag = 0)		
{
	set_name( "丧门斧");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "axe");			
	set_weight(5000);		
	
	set("unit", "柄");
	set("long", "这是一柄造型奇特的大斧。");
	set("value", 1500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N掣出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n反别腰后。");
	set("apply/damage", 300);			
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp