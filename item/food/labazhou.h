//laba_zhou.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIlaba_zhou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name
	
	set("unit", "��");
	set("long", "����һ�����࣬����������ð��أ����һ�������ݴ���׳彫������һ���ྡ������֮ɫ������ȥ˵�����Ĺ��졣����ҩ���̱ǣ��䶾��֪��");
	set("value", 50000);
  
};

virtual int do_use(CChar * me, CContainer * target)
{
	
	if ( me->query_temp("num" ) > 0 )
	{
		me->add_temp("num", 1);
		me->add("max_mp", -100);
		message_vision( "$N�ֺ���һ�������ֻ࣬���øγ���ϣ��������ѣ�ԭ���ȵ�̫��̫�࣬ҩЧ�ʵ��䷴��" , me);
	}
	
	else
	{
		me->add("max_mp", 100);
		me->add("mp", 100);
		message_vision( "$N����һ�������࣬��Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��..." , me);
		me->set_temp("num", 1);
	}
	
	me->unconcious();
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp