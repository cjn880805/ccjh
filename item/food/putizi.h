//putizi.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIputizi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("unit", "��");
	set("long", "����һ�ž�Ө����������ӣ�������ɽ������ǰ����ϡ�ޱȣ�������������֮ʵ�����ܻ��ٽ٣���ǧ�֣������ͬ�١�");
	set("value", 1000000);

};

virtual int do_use(CChar * me, CContainer * target)
{
	int mp_limit, hp_limit, mp_skill, add_skill, improve;

	mp_limit = me->query_skill("mp")*10;
	hp_limit = me->query("max_hp");
	mp_skill = me->query_skill("mp", 1);
	
	if ( hp_limit <= mp_limit  )
	{
		improve = mp_limit - hp_limit;

		if ( improve < 100 )
		{ 
			add_skill = mp_skill + (100 - improve)/5 + 1;
			me->set_skill("mp", add_skill );
		}
	}
	
	me->add("max_hp", 100);
	me->add("hp", 100);

	message_vision( "$N����һ�������ӣ���Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��..." , me);
	me->unconcious();
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp