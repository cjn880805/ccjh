//qingzugang.h

//Sample for ITEM: ����
//coded by wolfman
//data: 2001-7-23

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIqingzugang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

	set_weight(5000);		//set item weight

	set("long", "һ���������ֿ��������ӡ�");
	set("unit", "��");
	set("base_value", 1);
	set("material", "steel");
};

EQUIP_END;
