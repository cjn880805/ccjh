//xiaotianchi.h

//Sample for room: 小天池
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_xiaotianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小天池");
	
	add_npc("pub_youke");
	add_npc("pub_old");    // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外黑风口", "关外黑风口", "关外小天池");
	add_door("关外长白瀑布", "关外长白瀑布", "关外小天池");

    set("long","小天池又称长白镜湖，圆圆如镜。湖水碧蓝，林海峭壁倒映其间，风光幽丽，一层绿里透红的细沙，均匀地铺在湖底，恰似展开着的一幅金丝绒毯。相传天上仙女每日天池中沐浴，洗毕就到天豁峰的峰颠，坐在两个峰尖中间的开阔岩石上，对着小天池打扮梳妆，故名镜湖。" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("wei/renwu1") && !me->query("wei/renwu5") 
		&& me->query_temp("wei/renwu5_9") && !me->query_temp("wei/renwu5_12"))
	{
		say("斜阳透过天豁峰顶，将橙黄的余辉洒向小天池，直染得小天池之水犹如琥珀色的淳醉葡萄美酒。你忍不住想要捧一口来尝一尝！",me);
		AddMenuItem("装水", "$0zhuang $1", me);
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
			if(!me->query_temp("wei/renwu5_11"))//杀死神龙教老者
			{
				tell_object(me,"\n$HIC突然你听到一声断喝：“大胆贼人，竟敢偷取圣水！”\n");
				tell_object(me,"神龙教老者突然向你发起了攻击。\n");
				
				CFightRoom * obj;
				CContainer * env = me->environment();
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name("神龙教老者的战斗", "fight_room");		
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
				tell_object(me,"\n你拿出一个牛皮酒袋，放在池中装满了水。\n");
				jiudai->set("owner1",me->id(1));
				me->set_temp("wei/renwu5_12",1);//取得天池之水
			}
		}
		else
		{
			tell_object(me,"\n你看了看身上，没有找到可以装水的器皿，看来似乎要找个$YEL酒袋$COM。\n");
		}
	}
	return 1;
}
ROOM_END;
