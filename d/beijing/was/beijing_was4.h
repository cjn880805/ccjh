//beijing_was4.h  ���µ�4��

RESIDENT_BEGIN(CRbeijing_was4);

virtual void create()
{
	set_name( "���µ��Ĳ�");
	set("resident", "����");

	add_npc("was_fanseng");
	add_npc("was_fanseng");
	add_npc("was_fanseng");
	add_npc("was_fanseng");
	add_npc("was_fanseng");

	add_door("���µ�����", "�������µ�����", "�������µ��Ĳ�");
	add_door("���µ����", "�������µ����", "�������µ��Ĳ�");
};


int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query_temp("was/renwu2_5"))
		{
			me->move(load_room("��������"));
			return 0;
		}
		if(me->query_temp("was/master"))
		{
			//CChar * who=me->query_leader();
			CUser * player1=find_online(me->querystr_temp("was/����"));
			if(player1)
			//if(player1 && EQUALSTR(player1->name(1),who->name(1)))
			{
				CContainer * player2=present(player1->id(1));
				if(!player2)
					return notify_fail("$HIR������Ķ���ʧȥ����ϵ����������ȴ�����");
			}
		}
		else if(me->query_temp("was/leader"))
		{
			CUser * player3=find_online(me->querystr_temp("was/����"));
			if(player3)
			{
				CContainer * player4=present(player3->id(1));
				if(!player4)
					return notify_fail("$HIR������Ķ���ʧȥ����ϵ����������ȴ�����");
			}
		}
		CContainer * ShouWei=present("fan seng");
		if(ShouWei)
		{
			char msg[255];
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set("room_locked", FIGHT_NO_FLEE);
			obj->set_name(snprintf(msg, 255,"%s��ս��", ShouWei->name(1)),"fight_room");		
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
			
			ShouWei->move(obj);
			obj->Join_Team((CChar * )ShouWei, CFightRoom::FIGHT_TEAM_A);
			obj->Begin_Fight(0);
			return notify_fail(" ");
		}
	}
	return CRoom::valid_leave(me, dir);
}
RESIDENT_END;
