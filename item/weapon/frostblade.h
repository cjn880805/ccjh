//frostblade.h ����֮��
//coded by Teapot
//L:ast modify @  2001-02-20

EQUIP_BEGIN(CIfrostblade);

virtual void create(int nFlag = 0)	
{
	set_name( "����֮��");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "blade");		
	set_weight(20000);	
	
	set("unit", "��");
	set("value", 0l);
	set("material", "sapphine");
	set("wield_msg",  "$N�����ڵ����ϵ��ֻ����ĳ������ʱ����������" );
	set("unwield_msg",  "$N���������ʣ������ʱ��ů�˺ܶࡣ" );
	set("apply/damage", 85);
	set("is_frostblade",1);
};


EQUIP_END;



