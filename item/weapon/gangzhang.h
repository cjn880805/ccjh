EQUIP_BEGIN(CIGangZhang);

void create(int nFlag = 0)	
{
	set_name("����", "gang zhang");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "staff");		
	set_weight(5000);	

	set("unit", "��");
	set("long", "����һ�����صĸ��ȡ�");
	set("value", 1500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N���һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n������䡣");

	set("apply/damage", 25);
};



EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp