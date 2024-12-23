//zijin_staff.h
//紫金天蛇杖

EQUIP_BEGIN(CIzijin_staff);

void create(int nFlag = 0)		
{
	set_name( "紫金天蛇杖");

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "staff");		
	set_weight(10000);	

	set("unit", "根");
	set("long", "这是用来召唤泰山妖孽的紫金天蛇杖。");
	set("value", 15000);
	set("material", "gold");
	set("wield_msg", "$N擎起一根$n，握在手中。");
	set("unwield_msg", "$N放下手中的$n。");

	set("apply/damage", 50 + random(150) );	
	
	set("duration", 200);
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIG$w在$n身上化成一股绿烟，消散不见了……$COM";
	}
	
	return 0;
}

EQUIP_END;
