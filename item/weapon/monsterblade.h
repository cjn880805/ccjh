
EQUIP_BEGIN(CImonsterblade);

virtual void create(int nFlag = 0)	
{
	set_name( "$HIR��������$COM");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "blade");		
	set_weight(20000);	
	
	set("unit", "��");
	set("value", 5000);
	set("material", "topaz");
	set("apply/damage", 160);
	set("item_make",1);
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	victim->receive_wound("hp",300,me);
    tell_object(victim,"�㱻$HIR��������$COM�۳���Ѫ�����ˣ�");
	return 0;
}

EQUIP_END;



