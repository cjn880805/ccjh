
EQUIP_BEGIN(CIshezhang);

void create(int nFlag = 0)		
{
	set_name( "蛇杖");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "staff");		
	set_weight(2000);	

	set("unit", "根");
	set("long", "这是一根蛇杖, 杖头一条小蛇, 红舌伸缩, 十分诡异。");
	set("value", 300);
	set("material", "leather");
	set("wield_msg", "$N「唰」的一声提起一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n收回背后。");

	set("apply/damage", 35);				
};

EQUIP_END;
