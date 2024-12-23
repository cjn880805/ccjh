//qin.h
EQUIP_BEGIN(CIqin);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��������");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "music");
	set("music_type", "qin");

	set_weight(6000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ���ð������ɵ����١�");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N�ӱ���$n�������С�");
	set("unwield_msg", "$N�����е�$n�Żر���");
	set("apply/damage", 100);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp