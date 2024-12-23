//huaji.h
//xiaowu

EQUIP_BEGIN(CIhuaji);

virtual void create(int nFlag = 0)		
{
	set_name( "画戟");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "club");		
	set_weight(5000);	

	set("unit", "杆");
	set("long", "这是一根镔铁梨花龙纹戟，长可丈二，戟头隐隐透出寒光。");
	set("value", 3500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N从马鞍边解下一杆$n夹在胁下。");
	set("unwield_msg", "$N将$n挂到鞍桥边。");

	set("apply/damage", 70);				

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp