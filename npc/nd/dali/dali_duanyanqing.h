// duanyanqing.c 段延庆
//sound 2001-07-16

NPC_BEGIN(CNdali_duanyanqing);

virtual void create()
{
	set_name("段庆延", "duan yanqing");
	set("gender", "男性");
	set("nickname","恶贯满盈");
	set("age", 45);
	set("long", 
		"他就是四大恶人之首，人称恶贯满盈的段延庆。\n"
		"他本是大理段氏皇子，由于大臣反叛作乱而双腿残废、罹\n"
		"毒甚深。流落江湖后与叶二娘、南海鳄神、云中鹤和称四\n"
		"大恶人。在江湖上端的是无恶不作。\n"
/*		"他身穿一件青布长袍，身高五尺有余，脸上常年戴一张人\n"
		"皮面具，喜怒哀乐一丝不露。体格瘦长，双腿齐膝而断，\n"
		"只能用腋下的两根镔铁拐杖代步，但行走如飞，反比常人\n"
		"更快！\n"*/);
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("icon",old_man1);	

        set("chat_chance_combat", 3);
//	set("chat_msg_combat", ({
//		(: exert_function, "recover" :),
//	}) );
	set("chat_chance", 1);

	set("hp", 4000);
	set("max_hp", 4000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 180000);
	set("shen_type", -1);
	 
	set_skill("force", 120);
	set_skill("kurong_changong", 120);
	set_skill("finger", 120);              // 基本手法
	set_skill("yiyang_zhi", 120);
	set_skill("dodge", 130);
	set_skill("tiannan_step", 120);        // 逍遥游
	set_skill("parry", 120);
	set_skill("staff", 120);
	set_skill("duanjia_sword", 120);
	
	map_skill("force", "kurong_changong");
	map_skill("finger", "yiyang_zhi");
	map_skill("dodge", "tiannan_step");
	map_skill("parry", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	
	
        carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()						//NPC自动聊天
{
	switch(random(2))
	{
	case 0:
		return 	"段延庆叹了口气道：“唉……不知何时才能重登大理宝座！”";
	case 1:
		return 	"段延庆喃喃道：“段正德那厮若知我回来，定会将皇位拱手相让，哈哈哈！";
	}	
	return 0;
}
/*
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) )
	{
                remove_call_out("check_skills");
                call_out("check_skills", 2, ob);
        }
}

void check_skills(object ob)
{
	mapping skl; 
	object  me;
	string *sname;
	int i, counter, ob_shen;

	me = this_object();
	skl = ob->query_skills();
	sname  = sort_array( keys(skl), (: strcmp :) );
	ob_shen = (int)ob->query("shen");

	counter = 0;
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] >= 100)
			counter++;
	}

	if((counter >= 3) && (ob_shen > 0))
	{
		me->set_leader(ob);
	
		if ( !environment(me)->query("no_fight"))
		{
			call_out("do_kill", 1, me, ob);
			return ;
		}
		else
		{
			call_out("waiting", 0, me, ob);
			return ;
		}
	}
	return ;
}

int do_kill(object me, object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision( "$N对$n说道：老子一见正派高手就生气。"
			+RANK_D->query_rude(dest)+"，纳命来！\n" , me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me, dest);
	}
	else  
		call_out("waiting", 1, me, dest);
	
	return 1;
}

int waiting(object me, object dest)
{
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			call_out("do_back", 1, me);
			return 1;
		}
		else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}
		else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me, object dest)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	        return 1;
	}

	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") ==	dest->query("name") )
	{
		call_out("do_back", 1, me);
        return 1;
	}
	
	call_out("waiting", 0, me, dest);
	return 1;
}

int do_back(object me)
{

	me->move("/d/city/xidajie2");
	message("vision", "段延庆走了过来，嗤地一声冷笑，说道：又除了一个道貌岸然的伪君子。\n", 
		environment(), me );

	me->set_leader(0);
	return 1;
}
*/
NPC_END;