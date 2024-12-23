
EQUIP_BEGIN(CImonstersword);

virtual void create(int nFlag = 0)	
{
	set_name( "$HIY飞血金剑$COM");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");		
	set_weight(20000);	
	
	set("unit", "把");
	set("value", 5000);
	set("material", "topaz");
	set("apply/damage", 160);
	set("item_make",1);
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	victim->receive_wound("hp",300,me);
    tell_object(victim,"你被$HIY飞血金剑$COM折出的血光所伤！");
	return 0;
}

EQUIP_END;



