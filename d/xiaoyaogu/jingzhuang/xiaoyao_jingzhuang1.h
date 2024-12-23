//jingzhuang1.h
//Sample for room: 大理城经幢1

ROOM_BEGIN(CRXiaoYao_jingzhuang1);

virtual void create()
{
	set_name( "大理城经幢1");
	set("no_autosave",1);

	add_npc("xy_qiaozhongren");
	add_door("大理城经幢2", "逍遥谷大理城经幢2", "逍遥谷大理城经幢1");
	add_door("逍遥谷紫莲峰山路5", "逍遥谷紫莲峰山路5", "逍遥谷大理城经幢1");

	set("long", "雕四大天王像，高约四尺，批甲戴胄，手持斧钺，威严庄重。三人足踏鬼奴。一鬼奴肌肉暴起，右手挽蛇，蛇嘴正触鬼奴下腭；另俩鬼奴戴镣。一天神足下三人，中间一人正以双手各托天王一足。天王之间遍刻梵文佛经。" );
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
			obj->set_name( "白少庄主的战斗", "fight_room");		
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
