//huaji.h
//xiaowu

EQUIP_BEGIN(CIhuaji);

virtual void create(int nFlag = 0)		
{
	set_name( "���");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "club");		
	set_weight(5000);	

	set("unit", "��");
	set("long", "����һ�������滨����ꪣ������ɶ����ͷ����͸�����⡣");
	set("value", 3500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N�����߽���һ��$n����в�¡�");
	set("unwield_msg", "$N��$n�ҵ����űߡ�");

	set("apply/damage", 70);				

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp