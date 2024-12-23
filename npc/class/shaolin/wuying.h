//wuying.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_wuying);

void create()
{
	set_name("无名老僧",  "wuming seng");
    set("long","他就是少林无名老僧，看起来已经是风烛残年。而且双腿残废。 " );
    
    create_family("少林派",34, "弟子");
    set("attitude", "peaceful");

	set("icon",old_monk);

	set("title", "少林高僧");

	   set("age", 95);
    set("gender", "男性");
    set("shen_type", 1);
    set("no_drop",1);
	
    set("con", 30);
    set("dex", 30);
    set("int", 30);
    set("str", 30);
	set("per", 15);
	set("ker", 10);

    set("max_mp", 5500);
    set("max_hp", 30000);
        
	set("mp_factor", 150);
      
	set("repute", -100000);
    set("combat_exp", 3500000);

    set_skill("buddhism",300); 
    set_skill("dodge", 300);
    set_skill("force", 300);
    set_skill("literate",300);
    set_skill("parry", 300);
    set_skill("sword", 300);
    set_skill("finger", 300);
	set_skill("wuying_jian", 300);
    set_skill("hunyuan_yiqi", 300);
    set_skill("shaolin_shenfa", 300);
    set_skill("club", 300);
    set_skill("claw", 300);
    set_skill("yizhi_chan", 300);
    set_skill("staff", 300);   
        
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "wuying_jian");
	map_skill("sword", "wuying_jian");
	                  
	set("chat_chance_combat", 15);
	set("chat_chance", 2);
	    
    carry_object("jiasha")->wear();
    carry_object("changjian")->wield();
};

char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("sword wuying", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

char * chat_msg()
{
	if(! random(2))
         return  "$CYN无名僧人言到：“老纳自创之少林无影剑，举世无双。”";
           
	return "$CYN无名僧人言到：“老纳一身只败在独孤九剑之下，于是钻研20年终创出无敌的少林无影剑。”";	
}

void attempt_apprentice(CChar * who)
{    
	char msg[255];

	if (who->query("bai_wuming") == 1 )
	{
	    say("我不会再收你为徒了，你还是走吧！", who);
		SendMenu(who);
        return;
	}
        
	if (DIFFERSTR(who->querystr("family/family_name"), "少林派") )
	{
		say(snprintf(msg, 255, "%s与本派素无来往，不知此话从何谈起？", query_respect(who)), who);
		SendMenu(who);
		return;
	}
           
	if ( who->query_skill("buddhism", 1) < 200) 
	{
		say("悟禅之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。", who);
		say(snprintf(msg, 255, "在禅宗心法方面，%s是否还做得不够？", query_respect(who)), who);
		SendMenu(who);
		return;
	} 
            
	if (who->query_skill("parry", 1) < 200) 
	{
		say(snprintf(msg, 255, "在基本功方面，%s是否还做得不够？", query_respect(who)), who);
		SendMenu(who);
		return;
	}
             
	if (who->query_skill("literate",1) < 200) 
	{
		say("万事都讲一个缘字。", who);
		say(snprintf(msg, 255, "%s与佛无缘，还是请回吧。", query_respect(who)), who);
		SendMenu(who);
		return;
	}    
              
	if (who->query_skill("hunyuan_yiqi", 1) < 200) 
	{
		say("我少林派乃内家武功，最重视内功心法。", who); 
		say(snprintf(msg, 255, "%s是否还应该在内功上多下点功夫？", query_respect(who)), who);
		SendMenu(who);
		return;
	}

	if (who->query_skill("force", 1) < 200) 
	{
		say(snprintf(msg, 255, "在内功方面，%s是否还做得不够？", query_respect(who)), who);
		SendMenu(who);
		return;
	}
        
        
	if (who->query("family/generation") == 36)
	{
	    command("chat 0 想不到老纳在垂死之年，又觅得一个可塑之才\n好！老衲就将毕生的武学都传受于你！\n");
	    command(snprintf(msg, 255, "recruit %ld", who->object_id()));

		who->set("title", "少林派之世外高僧");
		who->UpdateMe();
        
        char name[40], new_name[40];
		strncpy(name, who->querystr("name"), 40);

		name[4] = 0;
		snprintf(new_name, 40, "渡%s", &name[2]);
		who->set("name", new_name); 
                
		who->set("bai_wuming", 1); 
        say(snprintf(msg, 255, "从今以后你的法名叫做%s，恭喜你荣升为少林派渡字辈弟子 !", new_name), who);
		SendMenu(who);		
        return;
	}
}

NPC_END;
