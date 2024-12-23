//dahuan_dan.h

//Sample for ITEM �󻹵�
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIdahuan_dan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�󻹵�");	//set item name

	set("unit", "��");
	set("long", "����һ���Ϻ쾧���Ĵ󻹵����˵���������ҩ����߹�������Ч�ޱȡ�");
	set("value", 10000);
	set("no_drop", "�������������뿪�㡣");
	set("shaolin",1);
 
};

virtual int do_use(CChar * me, CContainer * target)
{
	if ( DIFFERSTR(me->query_skill_mapped("force") , "hunyuan_yiqi" ))
	{
		me->add("max_mp", -10);
		message_vision("$N����һ�Ŵ󻹵���ֻ���øγ���ϣ�ԭ�������ڹ�����������������Ԫ��" , me);
		me->unconcious();
		destruct(this);
		return 1;
	}
	
	if ( me->query("condition/bonze_drug" ) > 0 )
	{
		me->add("max_mp", -1);
		message_vision( "$N����һ�Ŵ󻹵���ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��" , me);
	}
	else
	{
		me->add("max_mp", 1);
		message_vision( "$N����һ�Ŵ󻹵���ֻ������������ԴԴ���������Ϲ���������͸ʮ����¥���鲼��������ȫ������Ȼ��� !" , me);
	}
	
	me->apply_condition("bonze_drug", 60);
	
	destruct(this);
	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp