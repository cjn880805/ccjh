EQUIP_BEGIN(CIumbrella);


virtual void create(int nFlag = 0)
{
	set_name( "��ɡ");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");
	set_weight(1000);		

	set("unit", "��");
	set("value", 250000);
	set("material", "bamboo");
	set("long", "����һ����ֵĶ�������˵���С���ɡ����");
	set("wield_msg", "$N������ɫ����������Ҫ�����ˡ��������Ҳ��¡�\n$N�ͳ�һ��$n���������У�Ц�����������·�����");
	set("unequip_msg", "$N������Ȼ�������꣬$n��ûʲô���ˣ��������������ɡ�");
	set("apply/damage", 15);				

	set("skill/name","fengyu_wuqingzhi");	
	set("skill/exp_required",  0l);	
	set("skill/jing_cost",   100);	
	set("skill/difficulty",  20);
	set("skill/max_skill", 140 );	
	set("skill/min_skill",  0l); 

	set("no_drop", 1);
};

EQUIP_END;
