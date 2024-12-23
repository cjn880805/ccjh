//liuheta.h

//Sample for room: 杭州六和塔
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_liuheta);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州六和塔");
	
	add_npc("pub_guest");      // add by zdn 2001-07-14

	add_npc("wei_fang"); 

	add_door("杭州钱塘江畔", "杭州钱塘江畔", "杭州六和塔");

	set("long","爬上月轮山，便来到了六和塔之前。六和塔亦名六合塔，“六和”之名来之佛家的六种规约，“六合”就是“天，地，四方”的意思。这座八角塔有十三层，在它的飞檐翘角上括有一百零四只大铁铃。");

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
	if(userp(me) && !me->query("wei/renwu6"))
	{
		if(me->query("wei/renwu1") && me->query_temp("wei/renwu6_1")&& !me->query_temp("wei/renwu6_10"))
		{
			CContainer * env = me->environment();
			CContainer * wei=env->present("fang yu");
			if(wei)
			{
				tell_object(me, "\n$YEL方瑜突然向蒙面女子发动了攻击。\n");

				CFightRoom * obj =  (CFightRoom *)load_item("fight_room");	
				obj->set_name("方瑜与蒙面女子的战斗", "fight_room");
				obj->move(env);
				
				CNpc * robber = load_npc("wei_mengmian");
				((CChar *)robber)->set("owner",me->id(1));
				((CChar *)robber)->move(obj);
				obj->Join_Team(((CChar *)robber), CFightRoom::FIGHT_TEAM_A);
				
				wei->move(obj);
				wei->set("help",1);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_B);
				obj->Begin_Fight(0);
				
			}
		}
	}
}
ROOM_END;
