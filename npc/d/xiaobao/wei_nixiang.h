// wei_nixiang.h 泥像
// 秦波	2002、12、25

NPC_BEGIN(CNwei_nixiang);

virtual void create()
{
	set_name("泥像","ni xiang");
	set("icon", officer);

	set("gender", "男性");
	set("age", 1000);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	set("max_hp",1000);
	set("hp",1000);
	set("eff_hp",1000);

	set_weight(900000000);
	
	set("combat_exp", 3000+random(5000));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);

	call_out(do_die, 900);	
	set("no_kill",1);

};

virtual int do_look(CChar * me)
{
	say("它看上去青面獠牙，眼大如斗，高有丈余，犹如庙中泥鬼般模样！", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "look") == 0) 
		return CNpc::handle_action(comm, me, arg);

	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )
	{
		tell_object(me,"\n$HIC泥像摇晃了几下，一会儿又恢复了平静。");
		return 1;
	}
	if(me->query_temp("wei/renwu8_4") && !me->query_temp("wei/renwu8_5"))
	{
		CContainer * jian=me->present("taomujian");
		if(jian)
		{
			tell_object(me,"\n$HIC你披发仗剑，念起天魔大咒，四周荒野间顿时鬼哭狼嚎，天空上传来阵阵狞笑声：你们都给我死吧！");
			tell_object(me,"$HIC泥像似是受了什么诅咒般，摇晃了几下，轰然倒下，露出了背后的一道门来。\n");
			me->set_temp("wei/renwu8_5",1);//使用桃木剑破了泥像

			CContainer * env = load_room("杭州黄泥地道");
			CContainer * nixiang=env->present("nixiang");
			if(!nixiang)
			{
				nixiang=load_item("nixiang");
				nixiang->move(env);
			}
			move(load_room("temp_nixiang"));
			if(jian->query("count")>=5)
				destruct(jian);
			else
				jian->add("count",1);
		}
		else
		{
			tell_object(me,"\n$HIC泥像摇晃了几下，一会儿又恢复了平静。");
		}
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	npc->move(load_room("mf"));
}

NPC_END;




