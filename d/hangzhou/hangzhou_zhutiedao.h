//duyezuo.h 杭州铸铁地道

ROOM_BEGIN(CRhangzhou_zhutiedao);

virtual void create()		
{
	set_name( "铸铁地道");

	add_door("烈焰地道", "杭州烈焰地道", "杭州铸铁地道");
	add_door("杭州岳廊", "杭州岳廊", "杭州铸铁地道");

    
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query_temp("wei/renwu8_11") && me->query_temp("wei/renwu8_10"))
	{
		tell_object(me,"\n$HIR一个铜皮铁骨的机关人恶狠狠的向你扑了过来。");

		CFightRoom * obj;
		CContainer * env = me->environment();
		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "机关人的战斗", "fight_room");		
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
	if(EQUALSTR(dir,"杭州岳廊"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR你是怎么混进来的？", me);
			return 0;
		}
		else
		{
			if(!me->query_temp("wei/renwu8_11") )
			{
				message_vision("$HIR一个铜皮铁骨的机关人恶狠狠的看着$N，$N不由心中一战。", me);
				return 0;
			}
		}
	}
	return CRoom::valid_leave(me, dir);
}
ROOM_END;
