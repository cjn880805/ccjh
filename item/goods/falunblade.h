//falunblade.h ����ħ��
//coded by Teapot
//data: 2001-02-06

EQUIP_BEGIN(CIfalunblade);

virtual void create(int nFlag = 0)	
{
	set_name( "����ħ��");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "blade");		
	set_weight(10000);	
	
	set("unit", "��");
	set("long", "����һ�ѳ��ķ���ħ�������м�������Ѫ��������������ƥ��");
	set("value", 400000);
	set("material", "ruby");
	set("wield_msg",  "ֻ��$N�ٺ�һЦ������һ�ѳ��а��������Ѫ��������" );
	set("unwield_msg",  "ֻ��$N�ٺ�һЦ����Ѫ��ĵ���ر����ʡ�" );
	set("apply/damage", 800);	
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	me->add("repute",-10);
    tell_object(me, "�����һ��Ѫ��������ͷ����");
	return 0;
}

EQUIP_END;
