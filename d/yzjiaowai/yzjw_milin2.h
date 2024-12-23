//milin2.h

//Sample for room:  ����������2
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_milin2);

virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "������");

	add_npc("pub_kanzhuren");          //add by zdn 2001-07-16

	add_door("����ɽ·1","����ɽ·1","����������2");

    set("long","����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���");

}
	
/*
	Add by wolfman
 edit date 2001-7-24
*/
virtual int do_look(CChar * me)
{
	say("�������������������֣����������ӱȱ𴦵�Ҫ���ü�Ӳ�����ء�һֱ������ؤ����ӵ��ȶ�����������������ɵġ�",me);
	say("������е������Կ��ǿ�һ������һ�Ѻõ����ȣ���������һ��ʢˮ����Ͳ��",me);
	AddMenuItem("������","$9kanzuzi 0 kan",me);
	AddMenuItem("�Ȼ��ٿ�","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	
	char msg[255];

	if (strcmp(comm,"kanzuzi") == 0)
	{
		if (me->is_busy())
		{
			switch(random(10))
			{
			case 0:
			case 1:
				return notify_fail("����æ���أ����ٸ����ҷ�ָ�����");
				break;

			case 3:
				return notify_fail("�Ҷ��������ˣ�������û�ꣿ");
				break;

			case 7:
			case 8:
				return notify_fail("̫���ˣ�������Ъ��ɡ���");
				break;

			default:
				return notify_fail("��ѽ���ȵȵȣ��ҵĵ��β������ˡ���");
				break;
			}
		}

		if (me->query("hp") < 60)
			return notify_fail("�������̫���ˣ�������˯һ���ɡ�");
		
//error		if (EQUALSTR((me->query_weapon())->querystr("base_name"), "yuzhu_zhang"))		//������û��װ����
		if (!me->PresentName("chaidao",IS_ITEM))	//����������û�д���
			return notify_fail("��û�в���ô�������أ��ò������ñ������������ɣ�");
		
		me->add("hp",-50);
		message_vision("$N������һ����ǰ�����֣���׼һ������Ϊ����õ�����������ȥ����", me);
		
		if (me->PresentName("qingzugang",IS_ITEM))
		{
				message_vision("ͻȻ����������һ��ؤ�ﳤ�϶���$N�������벻�������ϻ���������̰�ĵļһ���ҹ���",me);
				message_vision("���Ŷ�׼$N��ƨ�ɷ���һ�ţ���$N�߳������֡�",me);
				me->move(load_room("����ɽ·1"));
				tell_room(me->environment(), 
					snprintf(msg, 255, "ֻ�����ء���һ����%s������������˳��������˸��Ľų��졣", me->name()), me);
				return 1;
		}

		switch(random(15))
		{
		case 0:
			load_item("qingzugang")->move(me);
			me->start_busy(3);
			message_vision("ֻ�������ꡱһ����һ�����ӵ���������",me);
			message_vision("$N�õ���һ�����ӡ�",me);
			return 1;
			break;

		case 1:
			load_item("zhutong")->move(me);
			me->start_busy(3);
			message_vision("ֻ�������ꡱһ����һ�����ӵ���������",me);
			message_vision("������񵶣�ѡ���������׳��һ�ؿ�ȥ��",me);
			message_vision("$N�õ���һ����Ͳ��",me);
			return 1;
			break;

		case 2:
			if( DIFFERSTR(me->querystr("family/family_name"), "ؤ��"))
			{
				message_vision("ͻȻ����������һ��ؤ�ﳤ�϶���$N����������͵��ؤ�ﱦ�񣬸��ҹ���ȥ��",me);
				message_vision("���Ŷ�׼$N��ƨ�ɷ���һ�ţ���$N�߳������֡�",me);
				me->move(load_room("����ɽ·1"));
				tell_room(me->environment(), 
					snprintf(msg, 255, "ֻ�����ء���һ����%s������������˳��������˸��Ľų��졣", me->name()), me);
				return 1;
			}
			
			load_item("qingzugang")->move(me);
			message_vision("�����ƫ�ˣ�ʲôҲû������\n��ʱ�߳�һλؤ�ﳤ�ϣ�����$NЦ�����˵�������ÿ��ˣ���������һ����������ȥ�ðɡ�",me);
			message_vision("$N�õ���һ�����ӡ�",me);
			return 1;
			break;
		
		default:
			message_vision("$N�㿳���ϰ��죬ʲôҲû���ţ����룺����ô����ҵ�����������ô������",me);
			return 1;
			break;
		}
	}
	return 0;
}


ROOM_END;
