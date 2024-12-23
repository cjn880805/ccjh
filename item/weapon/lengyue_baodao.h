//lengyue_baodao.h

//Sample for ITEM ���±���
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CILengYueBaoDao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���±���");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(10000);		//set item weight

	set("unit", "��");
	set("long", "����һ�ѷ����ı������������ý�˿��˿����һ��üë��֮�Ρ�");
	set("value", 100000);
	set("material", "steel");
	set("weapon/strength", 10);
	set("wield_msg",  "ֻ����ɭɭ��һ����⼤�������������˸����,���±�������$N������!" );
	set("unwield_msg",  "��ৡ���һ���������Ѳ��������±�����$N�������С�" );

	set("apply/damage", 1000);					//set the modifiers of attribute
 
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp