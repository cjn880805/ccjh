EQUIP_BEGIN(CIqingsi);


virtual void create(int nFlag = 0)
{
	set_name( "��z");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "whip");
	set_weight(1000);		

	set("unit", "��");
	set("value", 250000);
	set("material", "bamboo");
	set("long", "����һ�����ڵ��L󌡣");
	set("wield_msg", "$N�ԑ����ͳ�һ��С�t���������ĵĴ��_��ȡ��ʲ���������С�");
	set("unequip_msg", "$N�м��Č�����һ�|���z����");
	set("apply/damage", 60);				

	set("skill/name","jieyu_bian");	
	set("skill/exp_required",  0l);	
	set("skill/jing_cost",   100);	
	set("skill/difficulty",  20);
	set("skill/max_skill", 120 );	
	set("skill/min_skill",  0l); 


};

EQUIP_END;
