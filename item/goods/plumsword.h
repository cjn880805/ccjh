//plumsword.h ÷���Ž�
//coded by Teapot
//data: 2001-02-07

EQUIP_BEGIN(CIplumsword);

virtual void create(int nFlag = 0)	
{
	set_name( "÷���Ž�");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");		
	set_weight(20000);	
	
	set("unit", "��");
	set("value", 5000);
	set("material", "sapphine");
	set("wield_msg",  "$N��ɫ���£��Ա������г��һ����ɫ���ӵĳ�����" );
	set("unwield_msg",  "$N�����г�����ر�����ɫ��֮һ�ᡣ" );
	set("apply/damage", 60);
	set("mindtwist",2000+random(4000));
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	victim->add("hp",-50);
    tell_object(victim,"�㱻÷���Ž��۳��Ĳ�â����һ����");
	return 0;
}

EQUIP_END;



