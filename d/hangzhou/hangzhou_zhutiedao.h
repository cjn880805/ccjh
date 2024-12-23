//duyezuo.h ���������ص�

ROOM_BEGIN(CRhangzhou_zhutiedao);

virtual void create()		
{
	set_name( "�����ص�");

	add_door("����ص�", "��������ص�", "���������ص�");
	add_door("��������", "��������", "���������ص�");

    
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query_temp("wei/renwu8_11") && me->query_temp("wei/renwu8_10"))
	{
		tell_object(me,"\n$HIRһ��ͭƤ���ǵĻ����˶�ݺݵ��������˹�����");

		CFightRoom * obj;
		CContainer * env = me->environment();
		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "�����˵�ս��", "fight_room");		
		obj->move(env);
		
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

		CNpc * robber = load_npc("wei_jiguanren");
		((CChar *)robber)->set("owner",me->id(1));
		((CChar *)robber)->set("no_kill",1);
		((CChar *)robber)->move(obj);
		obj->Join_Team((CChar *)robber, CFightRoom::FIGHT_TEAM_A);				
		obj->Begin_Fight(0);
	}
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"��������"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR������ô������ģ�", me);
			return 0;
		}
		else
		{
			if(!me->query_temp("wei/renwu8_11") )
			{
				message_vision("$HIRһ��ͭƤ���ǵĻ����˶�ݺݵĿ���$N��$N��������һս��", me);
				return 0;
			}
		}
	}
	return CRoom::valid_leave(me, dir);
}
ROOM_END;
