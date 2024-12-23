//shizhu.h 石柱
ITEM_BEGIN(CIshizhu)

virtual void create(int nFlag = 0)		
{
	set_name("石柱","shi zhu");
	set("unit", "根");
	set("no_get", "");
	set_weight(1);
};


virtual int do_look(CChar * me)
{
	say("这是一根用石料精心雕柱而成的柱子，正中处有个凸起，看起来似乎象是个机关按扭。", me);
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6") && me->query_temp("xy/renwu6_3")==9)
	{
		AddMenuItem("按下机关", "$9an $1", me);
	}
	SendMenu(me);
	
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6") && me->query_temp("xy/renwu6_3")==9)
	{
		if(!strcmp(comm, "an")  )
			return do_an(me, arg);
	}
	return 0;
}

int do_an(CChar *me, char * arg)
{
	char msg[255];
	int i;
	CContainer * env=me->environment();
	if(env->query("index")==5)
	{
		CContainer * XyNpc;
		if(me->query_temp("xy/renwu6_5"))
			XyNpc=env->present("li qiou heng");
		else
			XyNpc=env->present("li cang hai");
		//计算九宫之术
		if(me->query_temp("xy/renwu6_3_1")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_9")==15 &&
			me->query_temp("xy/renwu6_3_2")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_8")==15 &&
			me->query_temp("xy/renwu6_3_3")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_7")==15 &&
			me->query_temp("xy/renwu6_3_4")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_6")==15 &&
			me->query_temp("xy/renwu6_3_1")+me->query_temp("xy/renwu6_3_2")+me->query_temp("xy/renwu6_3_3")==15 &&
			me->query_temp("xy/renwu6_3_1")+me->query_temp("xy/renwu6_3_4")+me->query_temp("xy/renwu6_3_7")==15 &&
			me->query_temp("xy/renwu6_3_3")+me->query_temp("xy/renwu6_3_6")+me->query_temp("xy/renwu6_3_9")==15 &&
			me->query_temp("xy/renwu6_3_7")+me->query_temp("xy/renwu6_3_8")+me->query_temp("xy/renwu6_3_9")==15
			&& XyNpc )
		{
			for(i=1;i<10;i++)
			{
				snprintf(msg, 255,"xy/renwu6_3_%d",i);
				me->delete_temp(msg);
			}
			if(me->query_temp("xy/renwu6_4"))
				me->set_temp("xy/renwu6_6",1);//第二次破解九宫之术,带李秋痕进入琅擐福地
			else
				me->set_temp("xy/renwu6_4",1);//第一次破解九宫之术,带李沧海进入琅擐福地
			tell_object(me,"\n$HIC你只觉得脚下地面一阵猛烈颤抖，周围传来轰隆隆的大响，过了许久，终于安静下来。\n");
			me->move(load_room("逍遥谷琅擐福地洞门"));
			XyNpc->move(load_room("逍遥谷琅擐福地洞门"));
			me->del("xy/renwu6_lost");
			destruct(this);
		}
		else
		{
			CChar * robber;
			for(i=1;i<10;i++)
			{
				snprintf(msg, 255,"xy/renwu6_3_%d",i);
				me->delete_temp(msg);
			}
			me->delete_temp("xy/renwu6_3");
			tell_object(me,"\n$HIC周围一股大力向你袭来，你只觉得一阵头晕目眩，胸口为之气结。\n");
			//失败，发生战斗
			
			if(XyNpc && me->query_temp("xy/renwu6_1") && EQUALSTR(XyNpc->querystr("owner"),me->id(1)) && me->query_temp("xy/renwu6_2"))
			{
				CFightRoom * obj = (CFightRoom *)load_item("fight_room");
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name( "飞凌九霄阁之战", "fight_room_feiling");		
				obj->move(env);
				
				(CChar * )XyNpc->move(obj);
				obj->Join_Team((CChar * )XyNpc, CFightRoom::FIGHT_TEAM_B);
				
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
				
				robber = load_npc("xy_shiwushi");
				robber->move(obj);
				robber->set("owner",me->id(1));
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);

				obj->Begin_Fight(0);
			}
			else
			{
				tell_object(me,"$HIC你眼前一黑，晕了过去。\n");
				me->unconcious();
				me->set("hp",me->query("eff_hp"));
				me->move(load_room("逍遥谷飞凌九宵阁正门"));
				if(me->query_temp("xy/renwu6_5"))
					me->delete_temp("xy/renwu6_4");
				else
					me->delete_temp("xy/renwu6_1");
				me->delete_temp("xy/renwu6_2");
			}
			destruct(this);
		}
	}	
	else
	{
		tell_object(me,"\n$YEL除了作弊，我真不知道你是怎么可能在这里进行任务，警告！！！！\n");
	}
	return 1;
}

ITEM_END;




