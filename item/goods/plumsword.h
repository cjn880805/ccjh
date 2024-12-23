//plumsword.h 梅音古剑
//coded by Teapot
//data: 2001-02-07

EQUIP_BEGIN(CIplumsword);

virtual void create(int nFlag = 0)	
{
	set_name( "梅音古剑");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");		
	set_weight(20000);	
	
	set("unit", "把");
	set("value", 5000);
	set("material", "sapphine");
	set("wield_msg",  "$N脸色肃穆，自背后剑鞘中抽出一把形色古朴的长剑。" );
	set("unwield_msg",  "$N将手中长剑插回背后，脸色随之一轻。" );
	set("apply/damage", 60);
	set("mindtwist",2000+random(4000));
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	victim->add("hp",-50);
    tell_object(victim,"你被梅音古剑折出的苍芒吓了一跳！");
	return 0;
}

EQUIP_END;



