//baihongjian.h

//Sample for ITEM: �׺罣
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIbaihongjian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�׺罣");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(8000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ����������ı�����");
	set("value", 10000);
	set("material", "steel");
	set("apply/per", 8);
	set("wield_msg", "$N��ৡ���һ�����һ������������$n�������С�");
	set("unwield_msg", "$N�����е�$n��ؽ��ʡ�");
	set("apply/damage", 100);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp