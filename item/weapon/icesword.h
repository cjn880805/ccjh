//icesword.h ����֮��
//coded by Teapot
//L:ast modify @  2001-02-20

EQUIP_BEGIN(CIicesword);

virtual void create(int nFlag = 0)	
{
	set_name( "����֮��");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");		
	set_weight(20000);	
	
	set("unit", "��");
	set("value", 0l);
	set("material", "sapphine");
	set("wield_msg",  "$N�����ڽ����ϵ��ֻ����ĳ������ʱ����������" );
	set("unwield_msg",  "$N���������ʣ������ʱ��ů�˺ܶࡣ" );
	set("apply/damage", 80);
	set("is_icesword",1);
};


EQUIP_END;



