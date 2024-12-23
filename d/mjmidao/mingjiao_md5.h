//mingjiao_md5.h



//Sample for room:  �����ص�5

//coded by cat
//data: 2001-3-20

ROOM_BEGIN(CRMingJiao_md5);


virtual void create()			//Call it when Room Create

{
	//set name of our room

	set_name( "�����ص�5");

	CDoor * door = add_door("�����ص�8", "�����ص�8", "�����ص�5");//��
	door->set_name( "�ص�");

	door = add_door("�����ص�7", "�����ص�7", "�����ص�5");//��
	door->set_name( "�ص�");

	door = add_door("�����ص�6", "�����ص�6", "�����ص�5");//��
	door->set_name( "�ص�");

	door = add_door("�����ص�1", "�����ص�1", "�����ص�5");//��
	door->set_name( "�ص�");
};

virtual int do_look(CChar * me)
{
	say("�ܵ���ǽ���ƺ��и����أ���һʱ�䲻֪���ò���ȥ�⶯����", me);
	AddMenuItem("����", "$0tui", me);
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
	return 0;
}

int do_tui(CChar * me)
{
	CRoom * room = load_room("������ʯ���8");
	int hurt;
	hurt = me->query("max_hp")/8 * (random(5)+1);

	switch (random(3))
	{
	case 0://boring
		message_vision ("$N�⶯���أ�ֻ����ɳɳһ�����죬ͷ�ϵ�����һ�ѻҳ�������û�κζ����ˡ�", me);
		return 0;

	case 1://unlucky
		message_vision ("$N�⶯���أ�ֻ���ѵ�һ������¶��һ���󶴣�$N���Լ��Ĳҽ����е�����ȥ��", me);
		me->move(room);
		message_vision ("$Nˤ���˺�����ʹ�����������ǻ��ȥ�ɣ����˾Ͳ�����ʹ�ˡ�", me);
		me->receive_damage("hp", hurt);
		me->FlushMyInfo();
		me->unconcious();
		return 0;

	case 2://very unlucky
		switch (random(5))
		{
		case 0://��
			message_vision ("$N��ԥ��һ�°⶯���ء�ֻ��һ�����ϡ��ļ��죬����˷��������������������", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 1://ľ
			message_vision ("$N��ԥ��һ�°⶯���ء�ֻ��һ�����顱�ľ��죬��ʮ����ľͬʱ���㴻����", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 2://ˮ
			message_vision ("$N��ԥ��һ�°⶯���ء�ֻ��һ�����͡������죬һ�ɶ�ˮ��ͷ���£�����Ƥ����ֱð���̡�", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 3://��
			message_vision ("$N��ԥ��һ�°⶯���ء�ֻ��һ�󡰺������ķ���������ͻȻð�������һ𣬶�ʱ�����ճ�һ�����ˡ�", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 4://��
			message_vision ("$N��ԥ��һ�°⶯���ء�ֻ��һ�󡰺�䡱�ľ��죬������ʯ��ͷ���£��������˸��߻���ء�", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
		}
		me->FlushMyInfo();
		return 0;
	}
	return 0;
}

ROOM_END;
