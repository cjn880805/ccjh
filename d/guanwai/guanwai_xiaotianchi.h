//xiaotianchi.h

//Sample for room: С���
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_xiaotianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С���");
	
	add_npc("pub_youke");
	add_npc("pub_old");    // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("����ڷ��", "����ڷ��", "����С���");
	add_door("���ⳤ���ٲ�", "���ⳤ���ٲ�", "����С���");

    set("long","С����ֳƳ��׾�����ԲԲ�羵����ˮ�������ֺ��ͱڵ�ӳ��䣬���������һ������͸���ϸɳ�����ȵ����ں��ף�ǡ��չ���ŵ�һ����˿��̺���ഫ������Ůÿ���������ԡ��ϴ�Ͼ͵�����ķ�ߣ�������������м�Ŀ�����ʯ�ϣ�����С��ش����ױ������������" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("wei/renwu1") && !me->query("wei/renwu5") 
		&& me->query_temp("wei/renwu5_9") && !me->query_temp("wei/renwu5_12"))
	{
		say("б��͸�����嶥�����ȻƵ��������С��أ�ֱȾ��С���֮ˮ��������ɫ�Ĵ����������ơ����̲�ס��Ҫ��һ������һ����",me);
		AddMenuItem("װˮ", "$0zhuang $1", me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(!strcmp(comm, "zhuang"))
	{
		return do_zhuang(me, arg);
	}
	return 0;
}

int do_zhuang(CChar *me, char * arg)
{
	if(me->query("wei/renwu1") && !me->query("wei/renwu5") 
		&& me->query_temp("wei/renwu5_9") && !me->query_temp("wei/renwu5_12"))
	{
		CContainer * jiudai=me->present("jiudai");
		if(jiudai)
		{
			if(!me->query_temp("wei/renwu5_11"))//ɱ������������
			{
				tell_object(me,"\n$HICͻȻ������һ���Ϻȣ��������ˣ�����͵ȡʥˮ����\n");
				tell_object(me,"����������ͻȻ���㷢���˹�����\n");
				
				CFightRoom * obj;
				CContainer * env = me->environment();
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name("���������ߵ�ս��", "fight_room");		
				obj->move(env);
				
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
				
				CContainer * wei=env->present("old man");
				if(!wei)
				{
					CChar * robber = load_npc("pub_old");
					robber->set("owner",me->id(1));
					robber->move(obj);
					obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
				}
				else
				{
					wei->set("owner",me->id(1));
					wei->move(obj);
					obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
				}
				obj->Begin_Fight(0);
			}
			else
			{
				tell_object(me,"\n���ó�һ��ţƤ�ƴ������ڳ���װ����ˮ��\n");
				jiudai->set("owner1",me->id(1));
				me->set_temp("wei/renwu5_12",1);//ȡ�����֮ˮ
			}
		}
		else
		{
			tell_object(me,"\n�㿴�˿����ϣ�û���ҵ�����װˮ�����󣬿����ƺ�Ҫ�Ҹ�$YEL�ƴ�$COM��\n");
		}
	}
	return 1;
}
ROOM_END;
