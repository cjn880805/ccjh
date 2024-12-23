//yaoqin.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-11-16
EQUIP_BEGIN(CIyaoqin);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield

	set("skill_type", "music");
	set("music_type", "qin");

	set_weight(5000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ�Ѹ�Ů�õ����٣��������൱����ϸ�塣");
	set("value", 300);
	set("material", "iron");
	set("wield_msg", "$N�ӱ��Ͻ���һ��$n��Ȼ��������С�");
	set("unwield_msg", "$N�������е�$n��");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp