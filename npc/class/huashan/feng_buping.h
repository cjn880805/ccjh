//feng_buping.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_feng_buping);

virtual void create()
{
	set_name("封不坦",  "feng butan");
	set("nickname", "狂风快剑");
	set("gender", "男性");
	set("class", "swordsman");
	set("title", "华山剑宗第十三代弟子");
	set("age", 45);
	set("long",
		"封不坦是华山剑宗第一高手，满脸戾气一张黄焦焦的面皮。");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("icon",young_man1);
	
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 30);
	set("max_hp",6000);
	
	set("combat_exp", 1000000);
	set("repute", -200000);
	set("apprentice_available", 3);
	
	set("chat_chance_combat", 80);
	
	set_skill("unarmed", 180);
	set_skill("sword", 230);
	set_skill("force", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("literate", 150);
	set_skill("huashan_sword", 180);
	set_skill("kuangfeng_jian", 230);
	set_skill("zixia_shengong", 160);
	set_skill("huashan_shenfa", 170);
	
	map_skill("sword", "kuangfeng_jian");
	map_skill("parry", "kuangfeng_jian");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	
	create_family("华山派", 13, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
				
	remove_call_out(do_reset);
	call_out(do_reset, 900, 0);
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("force powerup", 0);
			break;
	case 2:
			perform_action("sword feilong", 1);
			break;
	}
	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

    if( query("apprentice_available") ) 
	{
        if( me->query_int() < 20 )
		{
             say(snprintf(msg, 255, "我华山派以剑法为主，依我看%s不适合于学剑法。", query_respect(me)), me);
		}
		else 
		{
			say("好，好，好，很好。");
			command(snprintf(msg, 80, "recruit %ld", me->object_id()) );
			me->set("title", "华山剑宗第十四代弟子");
			add("apprentice_availavble", -1);
			me->UpdateMe();
			return;
        } 
	}
	else
        say("老夫今天已经收了三个弟子，不想再收徒了。", me);
      
	SendMenu(me);
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("apprentice_available", 3);
}

NPC_END;
