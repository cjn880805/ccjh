//shedangao.h

//Sample for ITEM �ߵ���
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshedangao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ߵ���");	//set item name

	set("unit", "��");
	set("long", "�������Ʒ���ߵ��ࡻ��");
	set("value", 100);

};
virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("max_hp")>=600)
	{
		tell_object(me,"��ԡ��ߵ��ࡻ����Ч�ã�");
		return 0;
	}
	if(me->query("max_hp")<400)
	{
		me->add("max_hp", 2);
		me->add("eff_hp", 2);
		me->add("hp",4);
	}
	else
	{
		me->add("max_hp",1);
		me->add("eff_hp", 1);
		me->add("hp",2);
	}
	message_vision( "$N����һ���ߵ��࣬�پ�һ�ɺƵ�����ֱӿ��������������..." , me);
	destruct(this);
	return 1;

}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp