//nuerxiang.h

//Sample for ITEM Ů����
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CInuerxiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ů����");	//set item name

	set_weight(50);

		set("long", "Ҷ����ü�����紦�ӡ�����ǲ��м�Ʒ��Ů���㡹��");
		set("unit", "��");
		set("value", 8000);
		set("remaining", 1);
		set("drink_supply", 25);

};
virtual int do_use(CChar * me, CContainer * target)
{
	int heal, recover, jing, e_jing, m_jing;
	
	if( me->is_busy() )
	{
		tell_object(me,"����һ��������û����ɡ�");
		return 0;
	}
	set("value", 0l);
	me->add("water", query("drink_supply"));
	m_jing = me->query("max_hp");
	heal = me->query_con();
	e_jing = me->query("eff_hp");
	if ( e_jing < m_jing )
	{ 	
		if ( (e_jing + heal) >= m_jing )
		{
			me->set("eff_hp", m_jing);
		}
		else
		{	
			me->add("eff_hp", heal);
		}	
	} 
	e_jing = me->query("eff_hp");
	jing = me->query("hp");
	recover = 30+heal;
    if (jing < e_jing )
	{
		if ( (jing + recover) >= e_jing )
		{
			me->set("hp", e_jing);
		}
		else
		{   
			me->add("hp", recover);
		}   
	}
	if( me->is_fighting() ) me->start_busy(2);
	add("remaining", -1);
	if ( query("remaining") )
	{
		message_vision("$N������裬������ζ��Ʒ�˼��ڡ�һ������ֱ����Ƣ��$N���þ���ö��ˡ�", me);
	}
	else 
	{ 
		message_vision("$N�����С����������ġ�Ů���㡹һ��������һ������ֱ����Ƣ��$N��ʱ���þ������", me);
		destruct(this);
	}
	return 1;

}
/***************************

int do_drink(string arg)
{
	int heal, recover, jing, e_jing, m_jing;
	
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( this_player()->query("water")
	   >= this_player()->max_water_capacity() )
	 return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0l);
	this_player()->add("water", query("drink_supply"));

	m_jing = this_player()->query("max_jing");
	heal = this_player()->query_con();
	e_jing = this_player()->query("eff_jing");

	if ( e_jing < m_jing )
	{ 	
		if ( (e_jing + heal) >= m_jing )
		{
			this_player()->set("eff_jing", m_jing);
		} else
		{	
			this_player()->add("eff_jing", heal);
		}	
	} 

	e_jing = this_player()->query("eff_jing");
	jing = this_player()->query("hp");
	recover = 30+heal;
    
	if (jing < e_jing )
	{
		if ( (jing + recover) >= e_jing )
		{
			this_player()->set("hp", e_jing);
		} else
		{   
			this_player()->add("hp", recover);
		}   
	}

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	add("remaining", -1);
	if ( query("remaining") )
	{
		message_vision("$N������裬������ζ��Ʒ�˼��ڡ�\n"+
		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
	} else 
	{ 
		 message_vision("$N�����С����������ġ�Ů���㡹һ��������\n"+
		"һ������ֱ����Ƣ��$N��ʱ���þ������\n", this_player());
		destruct(this_object());
	}
	return 1;
}

  ***************************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp