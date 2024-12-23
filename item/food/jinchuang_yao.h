//jinchuang_yao.h

//Sample for ITEM ��ҩ
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjinchuang_yao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ҩ");	//set item name

	set("unit", "��");
	set("long", "����һ�������Ч�����ֽ�ҩ��ר�������˵ȡ�");
	set("value", 2000);
	set("no_drop", "�������������뿪�㡣");

	set("shaolin",1);
	
};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("eff_hp") == me->query("max_hp"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��");
		
	if ( me->query_condition("bonze_drug") > 0 )
	{
		me->add("eff_hp", -50);
		message_vision("$N����һ����ҩ��ֻ���ؿڷ�����Ż����֫������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��", me);
	}
	else
	{
		me->receive_curing("hp", 50);
		message_vision("$N����һ����ҩ��ֻ��������������ɫ�������ö��ˡ�", me);
	}
	me->apply_condition("bonze_drug", 15);
    destruct(this);

    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp