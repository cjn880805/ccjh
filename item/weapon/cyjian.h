//cyjian.h	������
//�ز� 2002��3��14

EQUIP_BEGIN(CIcyjian);

virtual void create(int nFlag = 0)		
{
	set_name( "������");	
	
	set("wield_position", WIELD_RIGHT_HAND);		
	set("skill_type", "sword");			
	set_weight(20000);		
	
	set("unit", "��");
	set("value", 8000);
	set("material", "steel");
	set("long", "����ȫ�����ʦ������������������֮���������������������ɳ��ɱ�в�����������������΢�߲���Ѫ������������֮��ȥ�İ��졣��������ȫ��̵����֮����");
   	set("wield_msg","$N�⿪�಼�����ŵ�$n��ֻ�����Ǽ���ӳ�棬ԩ����죬����������ʦ�Ķ������ܰѳִ˽���");
   	set("unwield_msg", "$Nһ����������ɴС�ĵķ�ȥ�����Ѫ����������$n������������");
	set("apply/damage", 250+random(51));	
	set("duration", 100+random(50));
};


const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIW$w��$n���ϻ���һ���׹⣬��ɢ�����ˡ���$COM";
	}
	
	return 0;
}

virtual int Can_Equip(CChar * me)
{
	if(me->query_skill("taoism",1)<200)
	{
		say("��ĵ�ѧ�ķ��ȼ�������û��������ʦ�Ķ��������ܰѳִ˽���",me);
		SendMenu(me);
		return 0;
	}
	return 1;
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



