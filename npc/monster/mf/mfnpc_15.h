//mfnpc_15.h 星宿高级怪物
//秦波 2002、3、27

MFNPC_BEGIN(CNmfnpc_15);

virtual void create()
{
	static struct{
		char name[20], id[20];		//怪物名称
		int	 icon;			//图标
		int  chance;		//出现几率
	}mon[4] = {
		{"如梦子", "rumengzi", young_man1, 0,},
		{"苍生子", "cangshengzi", young_man1, 8,},
		{"天星子", "tianxingzi", young_man1, 16,},
		{"长空子", "changkongzi", young_man1, 24,},
	
		};

	int lvl = query("index");
	
	if(lvl < 1 || lvl > 4)
	{
		lvl = random(100);

		for(int i=4; i > 0; i--)
		{
			if(mon[i - 1].chance <= lvl)
			{
				lvl = i;
				break;
			}
		}
	}

	set("index", lvl);
//	set("no_chan",1);
	set_temp("apply/no_黯然消魂",1);
	set_temp("apply/no_情却千里",1);
	set_temp("apply/no_奔潮诀",1);

	lvl = lvl - 1;

	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("attitude", "aggressive");

	set("age", 40 + lvl);
	set("gender", "男性");

	set("mfnpc_lvl", 10 + lvl);
	set("nkgain", 30 + lvl * 5);

	set("chat_chance_combat", 20);
	set("chat_chance", 5);

	set("present_msg", "只听一声冷笑在你后面冒出，$N回头一看，原来是$n正在阴深的看着你。");
	call_out(do_die, 900);	
	
};

void eat_yao(char * yaopin)
{
	char msg[40];
	CContainer * yao = load_item(yaopin);
	yao->move(this);
	command(snprintf(msg, 40, "use %ld", yao->object_id()));
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
			perform_action("force hpsuck", 1);
			break;
	case 1:
			perform_action("force maxsuck", 1);
			break;
	case 2:
			if(query("hp") /2 < query("max_hp") / 3)
			{
				int i=random(4);
				if(!i)
					perform_action("force recover", 1);
				else if(i == 1)
					eat_yao("yaopin_1");
				else if(i == 2)
					eat_yao("yaopin_2");
				else
				{
					if(!random(5))
						eat_yao("jiuhua");
					else
						eat_yao("xiaohuan_dan");
				}
			}
			break;
	}
	return 0;
}

virtual int accept_fight(CChar *me)
{
	say("找死！");
	return do_kill(me);;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "kill") == 0)
		return do_kill(me);

	return CNpc::handle_action(comm, me, arg);
}

const char * invalid_fight(CChar * me)
{
	CContainer * env = environment();

	if( env->query("no_fight") )return "这里禁止战斗。";
	if(env->Query(IS_FIGHTROOM)) return "已经在战斗中了。";	
	if( !living(this) )	return "已经无法战斗了。"; 
	return 0;
}

int do_kill(CChar * me)
{
	char msg[80];
	CContainer * env = me->environment();
	
	const char * tmp = invalid_fight(me);
	if(tmp)
	{
		tell_object(me, tmp);
		return 1;
	}

	snprintf(msg, 80, "%s与%s的战斗", me->name(),this->name());
	CFightRoom * room = (CFightRoom *)load_item("fight_room");			//载入战斗精灵
		
	room->set_name(msg);
	room->move(env);

	me->move(room);
	room->Join_Team(me, CFightRoom::FIGHT_TEAM_A);		//加入战队

	do_copyme(me);
	move(room);
	room->Join_Team(this, CFightRoom::FIGHT_TEAM_B);

	room->Begin_Fight(1, 1);	//比试
	return 1;

}

void do_copyme(CChar * ob)
{
	int lev=(random(10)+15)/10;
	set("str", ob->query("str")+random(3));
	set("int", ob->query("int")+random(3));
	set("con", ob->query("con")+random(3));
	set("dex", ob->query("dex")+random(3));
	
	set("max_hp",ob->query("max_hp")*2);
	set("eff_hp",ob->query("max_hp")*2);
	set("hp", ob->query("max_hp")*2);
	set("max_mp", ob->query("max_mp"));
	set("mp",  ob->query("max_mp"));
	set("mp_factor", ob->query("mp_factor"));
	set("combat_exp", int(ob->query("combat_exp")*1.5));
	set("level",ob->query("level"));

	int i=ob->query("level");
	if((ob->query("level")<30 && ob->query_skill("force", 1) < 110 && ob->query_skill("dodge", 1) < 110 && ob->query_skill("parry", 1) < 110)|| (ob->query("level")>=30 && ob->query("level")<60 && ob->query_skill("force", 1) < 220 && ob->query_skill("dodge", 1) < 220 && ob->query_skill("parry", 1) < 220)|| (ob->query("level")>=60 && ob->query("level")<80 && ob->query_skill("force", 1) < 285 && ob->query_skill("dodge", 1) < 285 && ob->query_skill("parry", 1) < 285) || ob->query("level")>=80)
	{
		if(i>110)i=110;
	}
	else
		i=120;
        
	set_skill("throwing", 50+i*(lev+query("boss")));
    set_skill("feixing_shu", 50+i*(lev+query("boss")));        
	set_skill("force", 50+i*(lev+query("boss")));
	set_skill("huagong_dafa", 50+i*(lev+query("boss")));
	set_skill("dodge", 50+i*(lev+query("boss")));
	set_skill("zhaixinggong", 50+i*(lev+query("boss")));
	set_skill("strike",50+i*(lev+query("boss")));
	set_skill("xingxiu_duzhang", 50+i*(lev+query("boss")));
	set_skill("parry", 50+i*(lev+query("boss")));
	set_skill("staff", 50+i*(lev+query("boss")));
	set_skill("tianshan_zhang", 50+i*(lev+query("boss")));
	set_skill("literate", 50+i*(lev+query("boss")));
	set_skill("sanyin_wugongzhao", 50+i*(lev+query("boss")));
	set_skill("claw", 50+i*(lev+query("boss")));
	set_skill("poison", 50+i*(lev+query("boss")));
 
	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu_duzhang");
	map_skill("parry", "feixing_shu");
	map_skill("staff", "tianshan_zhang");
	map_skill("unarmed", "xingxiu_duzhang");
	map_skill("claw", "sanyin_wugongzhao");
      	
	prepare_skill("unarmed", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	npc->move(load_room("mf"));
	npc->call_out(do_die1, 60);
}

static void do_die1(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

MFNPC_END;




