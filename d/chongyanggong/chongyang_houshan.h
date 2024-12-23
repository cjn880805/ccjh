//houshan.h

//Sample for room:  ��������ɽ
//coded by zouwenbin
//data: 2000-12-2
//Last modify @ 2001-02-08
//Add a work.


ROOM_BEGIN(CRChongYang_houshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������ɽ");

	add_npc("quanzhen_wang");

	add_door("������С·", "������С·", "��������ɽ");

	set("long", "�����Ѿ���������������������ɽ�ĺ�ɽ���������ﻨ�㣬�������£�ɽ��Ҳƽ���ö��ˡ�");
    

};

virtual int do_look(CChar * me)
{
	say("�����Ѿ���������������������ɽ�ĺ�ɽ���������ﻨ�㣬�������£�ɽ��Ҳƽ���ö��ˡ�",me);
	say("�ݵ��ﳤ�������۴��̵��ܲ��������̲�ס�μ�����", me);
	AddMenuItem("���ܲ�", "$9ba 0 luobo", me);
	AddMenuItem("����", "", me);

	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	int i;
	if(strcmp(comm, "ba") == 0)
	{
		if (DIFFERSTR(arg, "luobo"))	return 0;

		if (me->is_busy())
		{
			return notify_fail("����������æ������");
		}

		CContainer * obj;
		message_vision("$N������һ����ϵĲݣ���׼һ������������������������", me);
		if(random(5) == 0)
		{
			obj=load_item("luobo");	//�ܲ�
			obj->move(me);
			message_vision("ֻ���ҵ�һ����$Nˤ���ڵ��ϣ�����ץ�˸��ϴ��ܲ���", me);
			i=random(me->query("level"))/2+1;
			me->add("combat_exp",i);
			me->start_busy(3);
			me->receive_damage("hp", i);
			return 1;
		}
		if(random(5) > 1)
		{
			message_vision("ֻ���ҵ�һ����$Nˤ���ڵ��ϣ�����ץ��һ����Ӳݡ�", me);
			i=random(me->query("level"))+1;
			me->start_busy(3);
			me->receive_damage("hp", i);
			return 1;
		}
		if(random(5) < 2 )
		{
			obj=load_item("caogeng");	//�ݸ�
			obj->move(me);
			message_vision("ֻ���ҵ�һ����$Nˤ���ڵ��ϣ�����ץ��һ�Ѳݸ���", me);
			i=random(me->query("level"))/4+1;
			me->add("combat_exp",i);
			me->start_busy(3);
			me->receive_damage("hp", i*2);
			return 1;
		}
		if(random(5) == 0)
		{
			obj=load_item("luobo");
			obj->move(me);
			message_vision("ֻ���ҵ�һ����$Nˤ���ڵ��ϣ�����ץ�˸��ϴ��ܲ����ҵ����Լ��Դ���", me);
			i=random(me->query("level"))/2+1;
			me->add("combat_exp",i);
			me->start_busy(3);
			me->receive_wound("hp", i);
		}
			CChar * cat = load_npc("animal_wangcai");
			cat->move(me->environment());
			message_vision("ͻȻ���ƺ������������С�����", me);
			message_vision("һֻ�����˹�����", me);
			cat->kill_ob(me);
		return 1;
	}
	return 0;
}


ROOM_END;
