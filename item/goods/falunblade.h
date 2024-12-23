//falunblade.h 法轮魔刀
//coded by Teapot
//data: 2001-02-06

EQUIP_BEGIN(CIfalunblade);

virtual void create(int nFlag = 0)	
{
	set_name( "法轮魔刀");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "blade");		
	set_weight(10000);	
	
	set("unit", "把");
	set("long", "这是一把赤红的法轮魔刀，刀刃间隐隐有血光流动，锋利无匹。");
	set("value", 400000);
	set("material", "ruby");
	set("wield_msg",  "只见$N嘿嘿一笑，摸出一把赤红邪刀，眼中血光流动。" );
	set("unwield_msg",  "只见$N嘿嘿一笑，将血红的刀插回背后刀鞘。" );
	set("apply/damage", 800);	
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	me->add("repute",-10);
    tell_object(me, "你觉得一股血气冲上心头……");
	return 0;
}

EQUIP_END;
