//fengwu.h

//Sample for room: ��Ĺ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_fengwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ����");


	add_door("��ĹС��", "��ĹС��", "��Ĺ����");
	add_door("��Ĺ������С��", "��Ĺ������С��", "��Ĺ����");

    set("long","������С��Ůι��ѵ�����ķ��ݣ��ݽ��Ϲ��źܶ�������εķ䳲����δ���ţ����ŵõ�һ����۵����㡣" );
	set("have_honey", 1);
};

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("have_honey", 1);
}

virtual int do_look(CChar * me)
{
	say("������С��Ůι��ѵ�����ķ��ݣ��ݽ��Ϲ��źܶ�������εķ䳲����δ���ţ����ŵõ�һ����۵����㡣", me);
	say("�����в�������ڷ����š��������Ե��䳲ȥ�ɵ���ۡ�", me);
	AddMenuItem("����", "$0caimi", me);
	AddMenuItem("����", "", me);

	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "caimi") == 0)
	{
		return do_caimi(me);
	}
	return 0;
}

int do_caimi(CChar * me)
{
	int level = me->query_skill("qufeng",1);
	int rate;
	rate = random(100);

	if(level == 0 && rate <= 20)
	{
		if(query("have_honey") == 1)
		{
			message_vision ("$N����һ�дӷ䳲��ץ��һ�޷��ۣ��������䶣����ͷ���塣", me);
			load_item("fengmi")->move(me);
			del("have_honey");
		}
		else
		{
			message_vision ("$N����һ���������ۣ������û�̵�ȴ����䶣����ͷ���塣", me);
			call_out(do_reset, 900);
		}
		if (rate == 0)
			rate = 5;
		me->apply_condition("yufeng_poison", rate * 3);
		return 0;
	}
	if(rate < level)
	{
		if(query("have_honey") == 1)
		{
			message_vision ("$Nʩչ����������������䣬�ɹ��ӷ䳲��ɼ���һ�޷��ۡ�", me);
			load_item("fengmi")->move(me);
			del("have_honey");
		}
		else
		{
			message_vision ("$Nʩչ����������������䣬ȴ���ַ䳲������ѱ��ɹ⡣", me);
			call_out(do_reset, 900);
		}
		return 0;
	}
	else
	{
		message_vision ("$N��ͼ�ɼ����ܣ������û�̵�ȴ����䶣����ͷ���塣", me);
		me->apply_condition("yufeng_poison", rate * 3);
	}
	return 0;
}

ROOM_END;
