EQUIP_BEGIN(CIyuzhu_zhang)

virtual void create(int nFlag = 0)		
{
	set_name("������", "yuzhu zhang");
	set_weight(5000);
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");		
	
	set("unit", "��");
	set("long", "һ�����ŵ����������ȡ�");
	set("value", 10000);
	set("material", "bamboo");
	set("wield_msg", "$N���һ���������������ץ�����С�");
	set("unwield_msg", "$N�����е������Ȳ�����С�");
	
	set("apply/damage", 50);
};

EQUIP_END;
