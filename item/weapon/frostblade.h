//frostblade.h 寒星之刀
//coded by Teapot
//L:ast modify @  2001-02-20

EQUIP_BEGIN(CIfrostblade);

virtual void create(int nFlag = 0)	
{
	set_name( "寒星之刀");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "blade");		
	set_weight(20000);	
	
	set("unit", "把");
	set("value", 0l);
	set("material", "sapphine");
	set("wield_msg",  "$N将放在刀鞘上的手缓缓的抽出，顿时寒气弥漫。" );
	set("unwield_msg",  "$N将刀收入鞘，阳光顿时温暖了很多。" );
	set("apply/damage", 85);
	set("is_frostblade",1);
};


EQUIP_END;



