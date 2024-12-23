// pub_jianning.h 建宇公主
// 秦波	2002、12、25

NPC_BEGIN(CNpub_jianning);

virtual void create()
{
	set_name("建宇公主", "jian ning" );
	set("gender", "女性");
	set("icon", young_woman3);
	set("long",  "她长的极美，其容色晶莹如玉，娇媚不可方物。");
	set("age", 17);
	set("per",36);

	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("max_hp",5000);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	add_money((1+random(5))*1000);
	call_out(do_die, 900);	
	set("no_kill",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query_temp("wei/renwu2_5"))
		{
			say("建宇公主地幽幽的说道：“不知道那个狠心薄情的死小宝，现在过的怎么样了！”",me);
			SendMenu(me);
			return 1;
		}
		else if(me->query_temp("wei/renwu2_4"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("询问关于小宝","xiaobao",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "xiaobao") )
			{
				me->set_temp("wei/renwu2_5",1);//建宇公主答应回家
				tell_object(me,"\n建宇公主舒了口气，高兴地说道：“怎么刚才不说是小宝叫你来的呀，其实我早想回去了！”");
				tell_object(me,"$HIC建宇公主向你吐了吐舌头。");
				tell_object(me,"$HIC建宇公主决定跟随你行动。\n");
				
				CChar * wei = load_npc("pub_jianning");
				wei->move(load_room("北京万宝楼"));
				wei->set("owner",me->id(1));
				wei->set_leader(me);
				destruct(this);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;