//jingzhuang1.h
//Sample for room: ����Ǿ���1

ROOM_BEGIN(CRXiaoYao_jingzhuang1);

virtual void create()
{
	set_name( "����Ǿ���1");
	set("no_autosave",1);

	add_npc("xy_qiaozhongren");
	add_door("����Ǿ���2", "��ң�ȴ���Ǿ���2", "��ң�ȴ���Ǿ���1");
	add_door("��ң��������ɽ·5", "��ң��������ɽ·5", "��ң�ȴ���Ǿ���1");

	set("long", "���Ĵ������񣬸�Լ�ĳߣ����״��У��ֳָ��ᣬ����ׯ�ء�������̤��ū��һ��ū���Ⱪ���������ߣ�����������ū����������ū���͡�һ�����������ˣ��м�һ������˫�ָ�������һ�㡣����֮�������ķ𾭡�" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") && me->query("xy/renwu7_pause")
			&& me->query_temp("xy/renwu7_4"))
		{	
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set("room_locked", FIGHT_LOCKED);
			obj->set_name( "����ׯ����ս��", "fight_room");		
			obj->move(env);
			
			CChar * robber;
			for(int i=0;i<3;i++)
			{
				robber=(CChar *)(env->present("playboy"));
				if(!robber)
					robber = load_npc("pub_playboy");
				robber->set("no_kill",1);
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);				
			}
			robber=(CChar *)(env->present("ouyang ke"));
			if(!robber)
				robber = load_npc("xy_ouyangke");
			robber->set("owner",me->id(1));
			robber->set("no_kill",1);
			robber->move(obj);
			obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);

			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

			obj->Begin_Fight(0);
		}
	}
}

ROOM_END;
