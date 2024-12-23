//xiaohuan_dan.h

//Sample for ITEM С����
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxiaohuan_dan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "С����");	//set item name

	set("unit", "��");
	set("long", "����һ��Ө����Բ��С�������˵���������ҩ��������������Ч�ޱȡ�");
	set("value", 10000);
	set("no_drop", "�������������뿪�㡣");
	set("shaolin",1);

};
virtual int do_use(CChar * me, CContainer * target)
{
    if ( me->query("mp") >= me->query("max_hp") * 2 )
	{
		 tell_object(me, "������û��Ҫ��С������");
		 return 0;
	}

	if( me->is_busy() )
	{
		tell_object(me, "�𼱣������ԣ�С�ı�ҭ���ˡ�");
		return 0;
	}

	me->start_busy(2);
	if ( DIFFERSTR(me->query_skill_mapped("force"), "hunyuan_yiqi" ))
	{
		me->set("mp", 0l);
		message_vision("$N����һ��С������ֻ�����������ѣ�ԭ�������ڹ�����������������Ϊ��", me);
		destruct(this);
		return 1;
	}

	if ( me->query("condition/bonze_drug") > 0 )
	{
		me->add("mp", -200);
		message_vision("$N����һ��С������ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��", me);
	}
	else
	{
		me->add("mp", 200);
		message_vision("$N����һ��С������ֻ�����������࣬��֫�ٺ�������ӯ�ޱȣ��������ڶ�����", me);
	}

	me->apply_condition("bonze_drug", 30);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp