//renshenguo.h

//Sample for ITEM �˲ι�
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIrenshenguo);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�˲ι�");	//set item name

	set("unit", "��");
	set("long", "����һֻ�˲ι�, �Ѿ�����, ����������ܲ�����С����");

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->add("max_mp",10);
	me->set("eff_hp",me->query("max_hp"));
	me->set("eff_mp",me->query("max_mp"));
	me->set("hp",me->query("max_hp"));
	me->set("mp",me->query("max_mp"));
	message_vision("$N����һö�˲ι���ֻ���þ���������Ѫ��ӯ����������ԴԴ�������������ٸе������ɿ�!",me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp