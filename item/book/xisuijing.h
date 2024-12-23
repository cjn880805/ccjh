//xisuijing.h

//Sample for ITEM: ϴ�辭
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIxisuijing);

//under, we will custom our item
virtual void create(int nFlag = 0)		//Call it when the item is created
{

	set_name( "ϴ�辭");	//set item name

 	set_weight(100);		//set item weight

	set("unit", "��");
 	set("long", "�Ȿ��ֽͲ�������������ѧ�伮���Ǵ�Ħ������ھ������׽һ�����(canwu)�����ľ����伮��");
	set("value",  10 );
	set("material", "paper");

};

virtual int do_look(CChar * me)
{
	CItem::do_look(me);
	
	AddMenuItem("����", "$9canwu $1", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "canwu") == 0)
		return do_study(me);

	return 0;
}

int do_study(CChar * me)
{
	char skill[][10] = {
		"whip",
		"finger",
		"hand",
		"cuff",
		"claw",
		"strike",};

	CContainer * where;
	int myskill, cost, i, exp;

	cost=50;
	where = me->environment();
	if (DIFFERSTR(where->querystr("base_name"), "�����´�ĦԺ��¥"))
		return notify_fail("ϴ�辭ֻ���ڴ�ĦԺ��¥�����");

	if (!me->query_skill("literate",1)||me->query_skill("literate",1)<100)
	{
		return notify_fail("���ֽͲ������ȥ������ʲô����������");		
	}
//	if (!me->query_skill("yijinjing",1)||me->query_skill("yijinjing",1)<100)
//	{
//		write("Ҳ����û���ڻ��ͨ�׽���������ϴ�辭Ī�����\n");
//		return 1;
//	}
	if (me->is_busy())
		return notify_fail("��������æ���ء�");
	if (me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��");
	exp = me->query_combat_exp();
	if (exp < 300000)
	{
		return notify_fail("��ĵȼ����������ܲ���ϴ�辭��");		
	}

	set("book_verb", "canwu");

	if (me->query("hp")>cost)
	{
		for ( i=6; i>0; i-- )
		{
			myskill=me->query_skill(skill[i-1], 1);
			if ( myskill<180 && myskill>1 && myskill < CChar::level2skill(me->query("level")))
			{
			    me->improve_skill(skill[i-1],(me->query_skill("literate",1)+me->query("int"))/2);
			}
		}
		tell_object(me, "�����ϴ�辭�ϵľ��ģ��ƺ��е��ĵá�", "study");
		me->receive_damage("hp", cost );
	}
	else
	{
		return notify_fail("�����ڹ���ƣ�룬�޷�ר����������ϴ�辭��");
	}

	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp