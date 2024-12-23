//qsdadao8.h
//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_qsdadao8);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "������ʯ���8");
	add_npc("pub_zhenwanjian");

	add_door("������ʯ���7", "������ʯ���7", "������ʯ���8");
	add_door("������ʯ���9", "������ʯ���9", "������ʯ���8");
	add_door("���̾�ľ�����", "���̾�ľ�����", "������ʯ���8");

	set("long", "������ƽ̹�����ƿ������������������ﻨ�㣬һƬ��ƽ��������ա�");
    

/*****************************************************

********************************************/

};


virtual int do_look(CChar * me)
{
	say("��·�Ա��п��ʯ��������ʮ�ֹ��졣������һ�������ɵ����ȥ��һ�ơ�", me);
	AddMenuItem("�����ư�!", "$0tui", me);
	AddMenuItem("����", "", me);

	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "tui") == 0)
	{
		return do_tui(me);
	}
	else if(strcmp(comm, "enter") == 0)
	{
		return do_enter(me);
	}
	return 0;
}

int do_tui(CChar * me)
{
	if(me->query_str() < 22)
	{
		message_vision ("$Nʹ�����̵�����������ȥ����ǰ�ľ�ʯ��˿������", me);
		return 0;
	}
	else
	{
		message_vision ("$N���һ��������!���������Ѿ�ʯ�ƿ���¶��һ����ɭɭ�Ķ��ڡ�", me);

		AddMenuItem("��ȥ����", "$0enter", me);
		AddMenuItem("����", "", me);
	
		SendMenu(me);
		return 0;
	}
}

int do_enter(CChar * me)
{
	int hurt;
	hurt = me->query("max_hp")/8 * (random(5)+1);
	switch (random(6))
	{
	case 0://��
		message_vision ("$N��ԥ��һ�£���������ض��С�ֻ��һ�����ϡ��ļ��죬����˷��������������������", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 1://ľ
		message_vision ("$N��ԥ��һ�£���������ض��С�ֻ��һ�����顱�ľ��죬��ʮ����ľͬʱ���㴻����", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 2://ˮ
		message_vision ("$N��ԥ��һ�£���������ض��С�ֻ��һ�����͡������죬һ�ɶ�ˮ��ͷ���£�����Ƥ����ֱð���̡�", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 3://��
		message_vision ("$N��ԥ��һ�£���������ض��С�ֻ��һ�󡰺������ķ���������ͻȻð�������һ𣬶�ʱ�����ճ�һ�����ˡ�", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 4://��
		message_vision ("$N��ԥ��һ�£���������ض��С�ֻ��һ�󡰺�䡱�ľ��죬������ʯ��ͷ���£��������˸��߻���ء�", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 5://lucky
		message_vision ("$N��ԥ��һ�£���������ض��С�", me);
		break;
	}

	CRoom * r = load_room("�����ص�4");
	me->move(r);
	return 0;
}

ROOM_END;
