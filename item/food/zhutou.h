//zhutou.h

//Sample for ITEM ��ͷ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzhutou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ͷ");	//set item name

	set_weight(350);
	
	set("long", "һ������ͷ��");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 15);
	set("wield_msg", "$Nץ��һ��$n���������е�������");
	set("material", "bone");
	set("apply/damage",1);

};

virtual int finish_eat()
{
//	if( !query("weapon_prop") ) return 0;
	set_name( "�еþ���Ĺ�ͷ");	//set item name
	set_weight(150);
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("long", "�еþ�������ͷ��");

	UpdateMe();
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp