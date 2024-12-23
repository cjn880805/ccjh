//fen.h

//Sample for ITEM �ߵ���
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ߵ���");	//set item name

	set("unit", "��");
	set("long", "�������˵ġ��ߵ��ۡ���");
	set("value", 2000);
 
};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("eff_hp") >= me->query("max_hp"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��");
	if(random(2)==0)
	{
		message_vision( "$N����һ���ߵ��ۣ��������������ۣ������ϵ�~~~~~" , me);
		destruct(this);
		return 1;
	}
	me->add("hp",30);
	me->add("eff_hp",20);
	message_vision( "$N����һ���ߵ��ۣ��پ�������ӿ���������Щ��" , me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp