//jinshe1.h

//Sample for ITEM: ��������ܸ���ϲ�
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIjinshe1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��������ܸ���ϲ�");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "��");
	set("long", "����һ���ñ�ֽд�ɵ��顣���飺��������ܸ������Ƥ���ƣ������Ѿ�����ܾ��ˡ�");
	set("material", "paper");

	set("no_drop", "�������������뿪�㡣");
	set("no_get", "�������������뿪�Ƕ���");
	set("no_put", "�����������ܷ����Ƕ���");

 
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "du") == 0)
		return do_du(me);
	return 0;
}

int do_du(CChar *me )
{
	CContainer * where ;
	int pxlevel; 
	int neili_lost;
	where = me->environment();
	
	if (where->query("pigging"))
	{
		tell_object(me,"�㻹��ר�Ĺ���ɣ�");
		return 1;
	}
	if (me->is_busy()) 
	{
		tell_object(me,"��������æ���ء�");
		return 1;
	}
	if( me->is_fighting() )
	{
		tell_object(me,"���޷���ս����ר�������ж���֪��");
		return 1;
	}
	if( !me->query_skill("literate", 1) )
	{
		tell_object(me,"���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�");
		return 1;
	}

	set("book_verb", "du");

	char msg[255];
	tell_room(me->environment(), snprintf(msg, 255, "%s��ר�ĵ��ж�������ܸ��", me->name()), me);
	
	if( me->query("hp") < 15 ) 
	{
		tell_object(me,"�����ڹ���ƣ�룬�޷�ר�������ж���֪��");
		return 1;
	}
	neili_lost = 5;
	if( me->query("mp") < neili_lost) 
	{
		tell_object(me,"�������������޷�������ô������书��");
		return 1;
	}
	pxlevel = me->query_skill("jinshe_jian", 1);
	if( CChar::level2skill(me->query("level")) < pxlevel) 
	{
		tell_object(me,"��ĵȼ�����������ô��Ҳû�á�");
		return 1;
	}
//	if( me->query_skill("jinshe_jian", 1) < 50)
//	{
//		tell_object(me,"���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫����ˣ�û��ѧ���κζ�����");
//		return 1;
//	}
	if( me->query_skill("jinshe_jian", 1) > 199)
	{
		tell_object(me,"���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����");
		return 1;
	}
	me->receive_damage("hp", 15);
	me->set("mp",me->query("mp")-neili_lost);
	me->improve_skill("jinshe_jian", me->query_skill("literate", 1)/3+1);
	tell_object(me,"���ж�������ܸ�������ĵá�");
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp