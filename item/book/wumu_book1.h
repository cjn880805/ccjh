//dujing_2.h

//Sample for ITEM: ���������顼�ϲ᡽��
//coded by oho
//data: 2000-10-30


ITEM_BEGIN(CIwumu_book1);



virtual void create(int nFlag = 0)		//Call it when the item is created
{
	int lvl = 0;
	
	if(! random(3))
	{
		lvl = 1;
		if(! random(5))
			lvl = 2;
	}

	if(nFlag) lvl = nFlag - 1;
	set("index", lvl + 1);

	static char book_name[][40] = {"���������顼�ϲ᡽��", "���������顼�в᡽��", "���������顼�²᡽��"};

	set_name(book_name[lvl], "wumu book");	//set item name
 	set_weight(1000);		//set item weight

	set("unit", "��");
	set("long", "��������д�Ĺ�����ƽ��������ս�����ĵú����飬������������ʿ��˵Ҳ��ûʲô������");
	set("value", 0l);
	set("material", "paper");

	set("skill/name","zhanjiang_jue");	// name of the skill
	set("skill/exp_required", 150000 + lvl * 300000);	// minimum combat experience required
	set("skill/jing_cost", 20 + lvl * 10);	// jing cost every time study this
	set("skill/difficulty", 25);	// the base int to learn this skill
	set("skill/max_skill", 80 + lvl * 80);	// the maximum level you can learn
	set("skill/min_skill", lvl * 80);  // the maximum level you can learn
	
	set("no_drop", 1);
	set("no_sell", 1);
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
	{
		if (me->query("max_mp") < 200)
		{
			tell_object(me, "�������������");
			return 1;
		}

		if(me->query("str") < 25 || me->query_str() < 40)
		{
			tell_object(me, "���������˵Ĳ�,ѧն������ʲô�ã��ؼ�����ȥ�ɣ���");
			return 1;
		}

		if ( me->query_skill("zhongpingqiang", 1) < 100)
		{
			tell_object(me, "�����ƽǹ�����������޷�ѧϰն������");
			return 1;
		}
		if( me->query_skill("wuhuduanmendao", 1) < 100)
		{
			tell_object(me, "����廢���ŵ������������޷�ѧϰն������");
			return 1;
		}
		if ( me->query_skill("changquan", 1) < 100)
		{
			tell_object(me, "��ĳ�ȭ�����������޷�ѧϰն������");
			return 1;
		}
		 
		return do_study(me);
	}

	return 0;
}

int do_study(CChar *me )
{
	if (me->is_busy()) 
		return notify_fail("��������æ���ء�");
		
	if ( me->is_fighting())
		return notify_fail("ս�����޷��Ķ���֪��");

	if ( me->query("hp") > 30 
		&& me->query_skill("zhanjiang_jue",1) >= query("skill/min_skill") 
		&& me->query_skill("zhanjiang_jue",1) <= query("skill/max_skill") )
	{
		me->receive_damage("hp", 30);
		me->improve_skill("zhanjiang_jue", (me->query_skill("zhanjiang_jue",1) + me->query("int")));
		message_channel("study", "$N����ר���ж��������顣", me);
		return 1;
	}

	return notify_fail("���������ѧ�����κ�֪ʶ��");
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp