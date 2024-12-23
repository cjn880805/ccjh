//beijing_was6.h  万安寺第六层

RESIDENT_BEGIN(CRbeijing_was6);

virtual void create()
{
	set_name( "万安寺第六层");
	set("resident", "北京");

	add_npc("was_lugunweng");
	add_npc("was_hemaoke");

	add_door("万安寺第五层", "北京万安寺第五层", "北京万安寺第六层");
	add_door("万安寺第七层", "北京万安寺第七层", "北京万安寺第六层");
};


int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query_temp("was/renwu2_5"))
		{
			me->move(load_room("北京万安寺"));
			return 0;
		}
		if(me->query_temp("was/master"))
		{
			//CChar * who=me->query_leader();
			CUser * player1=find_online(me->querystr_temp("was/队友"));
			if(player1)
			//if(player1 && EQUALSTR(player1->name(1),who->name(1)))
			{
				CContainer * player2=present(player1->id(1));
				if(!player2)
					return notify_fail("$HIR你与你的队友失去了联系，请在这里等待！！");
			}
		}
		else if(me->query_temp("was/leader"))
		{
			CUser * player3=find_online(me->querystr_temp("was/队友"));
			if(player3)
			{
				CContainer * player4=present(player3->id(1));
				if(!player4)
					return notify_fail("$HIR你与你的队友失去了联系，请在这里等待！！");
			}
		}
		CContainer * ShouWei=present("lu gun weng");
		CContainer * ShouWei1=present("he mao ke");
		if(ShouWei || ShouWei1)
			return notify_fail("\n$HIR你看到玄冥二老在一旁悠闲的做着，不由的停了下来。\n");
	}
	return CRoom::valid_leave(me, dir);
}
RESIDENT_END;
