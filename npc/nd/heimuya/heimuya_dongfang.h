//dongfang.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNHeiMUYa_dongfang);

virtual void create()
{
	
	set_name("东方爱莲","dong fang");
	
    set("nickname",  "天下无敌" );
    set("title", "日月神教教主");
    set("gender", "男性");
    set("shen_type", -1);
    set("age", 42);
    set("long","他就是日月神教教主。号称无人可敌，最近不知道为什么改名为「东方爱莲」。");
    set("attitude", "peaceful");
	set("icon",old_man2);
	
    set("per", 21);
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
	
    set("chat_chance", 1);
	
    set_inquiry("杨莲","你敢直称我爱人的名字,想找死呀？ ");
    set_inquiry("葵花宝典","如果你能帮我取得葵花宝典，我一定重重谢你。");
	
    set("hp", 4000);
    set("max_hp", 12000);
    set("mp", 4500);
    set("max_mp", 4500);
    set("mp_factor", 400);
	
    set("combat_exp", 2500000);
    
	
    set_skill("force", 250);             // 基本内功
    set_skill("finger", 250);            // 基本指法
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("dodge", 250);             // 基本躲闪
    set_skill("parry", 250);             // 基本招架
    set_skill("sword", 350);             // 基本剑法
    set_skill("pixie_jian", 350);        // 辟邪剑法
    set_skill("changquan", 280);         // 太祖长拳
    set_skill("literate", 100);          // 读书识字
    set_skill("kuihua_xinfa", 250);      // 葵花心法
	
    map_skill("force", "kuihua_xinfa");
    map_skill("sword", "pixie_jian");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	
    create_family("日月神教", 2, "教主");
	
    carry_object("xiuhua")->wield();
    carry_object("yan_dress")->wear();
	if (random(3)==0)
		carry_object("heiyugao");
	set("no_huan",1);
}


virtual void attempt_apprentice(CChar * player)
{
	
    if (player->query_int() < 30) 
	{
        say ("我不收资质差的弟子，您请回吧！",player);
    }else if (DIFFERSTR(player->querystr("gender"), "无性") )
	{
        say(" 要练神功，必须自宫。",player);
    }else if (player->query("repute") >100000 || player->query ("repute") < -100000 )
	{
        say("我黑木崖与世隔绝，向来不与您这种成名人物打交道，您请回吧！", player);
    }
	else
	{
		say("很好，很好。", player);
		SendMenu(player);
		recruit_apprentice(player);
		return;
	}
	
	SendMenu(player);
	
	
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if (me->query_temp("tmark/东") == 1 )
        message_vision("东方爱莲看了看$N，说道：咱们现在是谁也不欠谁,你不要再找我学习技艺了。", me);
	
    me->add_temp("tmark/东", -1);
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if(EQUALSTR(me->querystr("party/party_name"), "黑木崖") ) return 1;
    
    if (! me->query_temp("tmark/东"))
        return 0;
	
    return 1;
}

virtual int accept_object(CChar * player , CContainer * item)
{
	
	if ( EQUALSTR(item->querystr("base_name"), "kuihua") )	//没有kuihua baodian1这个物件！改为kuihua，Modify by Lanwood 2000-12-27
	{
		if (!player->query_temp("tmark/东")) 
			player->set_temp("tmark/东",100);
		
		message_vision("东方爱莲看了看$N送来的秘籍，点了点头，说道：难得你将宝典送回。你送我的东西我就收下了。作为补偿,你可以从我这里学点功夫。", player);
		player->add_temp("tmark/东", 100);
		
		return 1;
	}
	
	return 0;
}
NPC_END;