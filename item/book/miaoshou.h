//���ֿտ� miaoshou.h
//Lanwood 2001-02-10
//ѧϰ���ֿտ�֮��

ITEM_BEGIN(CImiaoshou);

virtual void create(int nFlag = 0)
{
	set_name( "���ֿտ������ؼ�");

 	set_weight(200);		

	set("unit", "��");
 	set("long", "����һ����顣");
	set("value",  1500 );
	set("material", "paper");
	set("skill/name","stealing");	// name of the skill
	set("skill/exp_required",  1000);
	set("skill/jing_cost",   20+random(20));
	set("skill/difficulty", 20 );
	set("skill/max_skill",  20);
	set("skill/min_skill", 0l);
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
	{
		//�ǹ�����ȱʡ�ж�
		if(! me->query("thief")) return 0;

		if(me->query("hp") < 50)
		{
			tell_object(me, "��е�ͷ���ۻ���ʲôҲ�����塣");
			return 1;
		}

		tell_object(me, "��͵͵�������ͳ�һ���ƾɵġ����ֿտ����š���Ѹ�ٷ��˼�ҳ���ƺ������ĵá�");

		me->add_temp("hp", -50);
		me->add_temp("mark/miaoshou", random(me->query_skill("stealing", 1)) + 1);
		me->start_busy(2);

		if( random(me->query_temp("mark/miaoshou")) > 20)
		{
			tell_object(me, "$YEL���ƺ������͵�Ե����У�Ȼ��Ѹ�ٽ���˺����");
			me->delete_temp("mark/miaoshou");
			me->add("thief", -1);
			destruct(this);
			return 1;
		}

		return 1;
	}

	return 0;
}

ITEM_END;
