// yan.c
//sound 2001-07-16

NPC_BEGIN(CNmurong_yan);

virtual void create()
{
	set_name("厉妈妈", "yan mama");
	set("gender", "女性");
	set("age", 50);      
	set("title","花肥房管事");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("icon",old_woman);
	
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_hp",1000);
	set("hp",1000);
	set("no_get","你没办法拿起这个人");
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling_shenfa",70);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan_gong",70);
	set_skill("blade",70);
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("gangdao")->wield();
	
	set_inquiry("名字", "我是曼佗罗山庄的花房管事。");
	set_inquiry("这里", "这里是花肥房，专门把夫人让处死的人做花肥。");
	set_inquiry("传闻",  "最近一个姓段的小子从我手里跑了。");
          
}
/*
void init()
{
	object me, ob;
	mapping fam;
	
	::init();
	
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) && fam["family_name"] != "姑苏慕容" ) )
	{
		command("say 近来花肥不太够，让老婆子我拿你做花肥吧！！！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}
*/
NPC_END;