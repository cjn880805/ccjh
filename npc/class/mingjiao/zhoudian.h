//zhoudian.h
//Lanwood
//2001-01-09

NPC_BEGIN(CNmingjiao_zhoudian);

virtual void create()
{
	set_name("周疯", "zhou feng");
	set("long","他是一位疯疯颠颠的老者，身穿一件白布长袍。他总是慌慌张张的，先天下之急而急。");
	
	set("title",  "明教五散人");
	set("nickname", "没事不颠有事颠");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "scholar");
	set("icon",young_man2);
	set_weight(50000000);
	
	set("age", 46);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);
	
	set_skill("force", 85);
	set_skill("hunyuan_yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin_shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang_quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");
	
	prepare_skill("cuff", "jingang_quan");
	create_family("明教", 3, "五散人");
	
	carry_object("baipao")->wear();
}
/*
virtual void init(CChar *me)
{
	CNpc::init(me);
	
	if (userp(me) && me->query_temp("fighting"))
	{
		//		do_attack(this_object(), this_player(), query_temp("weapon") );
		Do_Attack(this, me, 0 );
		me->add_temp("beat_count", 1);
	}       
}
*/
virtual int handle_action(char *comm, CChar *me, char * arg)
{
	CContainer * env = load_room("pk");
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )&& env->query("mj/start") && userp(me))
	{
		message_vision("$n横眉怒视$N，恨道：“在这大敌当前之际，你到底想做什么！！”", me, this);
		me->delete_temp("mf/exp");
		me->add("hp",-me->query("hp")/2);
		me->UpdateMe();
		me->start_busy(3);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}
void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me && !env->query(snprintf(msg, 255,"mj/kill_%s",this->name(1))))
		{
			env->add(snprintf(msg, 255,"mj/kill_%s",this->name(1)),1);
			env->add("mj/count",1);
			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIY%s$HIC新立奇功，斩获明教魔头$HIY%s%s$HIC！",me->name(1),this->querystr("title"),this->name(1)));
		}
	}
	CNpc::die();
}
NPC_END;



