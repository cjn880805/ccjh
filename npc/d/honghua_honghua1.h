//honghua1.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_honghua1);

virtual void create()
{

	set_name("绿营会众","lvying huizong");

	set("gender", "男性");
	set("age", 25);
	set("long","这是位手执长枪的绿营的清兵，也就是说是为满人卖命的汉人。");
	set("combat_exp", 20000);
    set("shen_type", 1);
	set("attitude", "heroism");
 	set("icon",young_man4);

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("club", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

    carry_object("changqiang")->wield();
    carry_object("junfu")->wear();
	add_money(20);

	set("no_kill",1);
}

virtual void init(CChar * player)
{
	if(! is_fighting() && userp(player))
	{
		if (random(2) == 1)
			message_vision("绿营会众悄悄告诉$N：身在绿营心在汉！" , player);
		else
			message_vision("绿营会众冲着$N挤了挤眼说：狗皇帝是从青楼地道被当家的逮着的！" , player);
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("wei/renwu8_11") && EQUALSTR(environment()->querystr("base_name"),"杭州岳廊" ))
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问关于依恋","yilian",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "yilian") )
		{
			tell_object(me,"\n绿营会众哼的一声，道：“看你这人贼眉鼠目就不像什么好人，找打！”\n");

			CFightRoom * obj;
			CChar * robber;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set_name( "绿营会众的战斗", "fight_room");	
			obj->set("room_locked", FIGHT_LOCKED);
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

			//检查绿营会众是否在场，如没有这个NPC则变一个
			/*
			wei=env->present("cheng xiaofeng");
			if(!wei)
			{
				robber = load_npc("mingjiao_chengchaofeng");
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
			}
			else
			{
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
			}
			*/
			for(int i=0;i<2;i++)
			{
				CContainer * wei=env->present("lvying huizong");
				if(!wei)
				{
					robber = load_npc("honghua_honghua1");
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
			}
			
			obj->Begin_Fight(0);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));
		if(me)
			me->set_temp("wei/renwu8_12",1);//打败保镖
	}
	CNpc::die();
}
NPC_END;