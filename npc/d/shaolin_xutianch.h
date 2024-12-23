// shaolin_xutianch.c 徐海岩

//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;

NPC_BEGIN(CNshaolin_xutianch);

virtual void create()
{
	set_name("徐海岩", "xu tianchuan");
	set("title",  "天地会青木堂护法");
	set("nickname", "八臂猿猴");
	set("gender", "男性");
	set("long", "他是青木堂数一数二的好手，手上功夫十分了得，尤其擅使一套猴拳。");
	set("age", 55);
	
	set("int", 30);
    	set("icon",old_man1);
	
	set("hp", 500);
	set("max_hp", 1500);
	set("shen_type", 1);
	
	set("combat_exp", 75000);
	set("attitude", "friendly");
	
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 90);
	set_skill("unarmed", 90);
	set_skill("hand", 100);
	set_skill("hunyuan_yiqi", 70);
	set_skill("shaolin_shenfa", 70);
	set_skill("houquan", 100);
	
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 35);
	set("env/wimpy", 50);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "houquan");
	map_skill("unarmed", "houquan");
	map_skill("parry", "houquan");
	
	set("chat_chance", 3);
	
	set_inquiry("陈远北","想见总舵主可不容易啊。");
	set_inquiry("天地会","只要是英雄好汉，都可以入我天地会。");
	set_inquiry("入会","只要入了我天地会，可以向会中各位好手学武功。");
	set_inquiry("去清复明膏","去药铺内室里仔细瞧瞧吧！");
	set_inquiry("暗号","敲三下！");
	set_inquiry("江湖威望",ask_weiwang);
	
	carry_object("cloth")->wear();
	add_money( 5000);
}

virtual char * chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "徐海岩想了想，说：有人想要进出皇宫，我得想个法子才好啊。";
	case 1:
		return "徐海岩说道: 江湖威望很重要，威望值高大有好处啊。";
	case 2:
		return "徐海岩突然说：自此传得众兄弟，后来相认团圆时。";
	case 3:
		return "徐海岩突然说：初进洪门结义兄，对天明誓表真心。";
	}
	return "";
}
/*
virtual void init(CChar *me)
{
	CNpc::init(me);
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}
*/
static char * ask_weiwang(CNpc *who,CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"你现在的江湖威望是 %ld" , me->query("weiwang") ), me);
	who->say("如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。", me);
	who->say("杀某些坏人或救某些好人可以提高江湖威望。", me);
	who->SendMenu(me);

	return "";
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"skills") == 0)
		return do_skills(me);
	return 0;
}

int do_skills(CChar * ob)
{
	if(wizardp(ob))  return 0;
	if (DIFFERSTR(ob->querystr("party/party_name"), "天地会")  )
	{
		message_vision("$N摇了摇头。",this);
		tell_object(ob,"徐海岩怒道：非天地会弟子不能察看！顿了一顿，又陪笑道:当然，巫师除外。");
		return 1;
	}
	
	//command(snprintf(msg,255,"tell %ld 我所有的武功如下：基本内功 (force) - 70\n基本轻功 (dodge) - 出神入化  70    基本招架 (parry) - 一代宗师  90    基本拳脚 (unarmed) - 一代宗师  90    基本手法 (hand) - 深不可测 100  □混元一气功 (hunyuan_yiqi) - 出神入化  70  □少林身法 (shaolin_shenfa) - 出神入化  70  □猴拳 (houquan) - 深不可测 100 ",ob->object_id() ) );
	return 1;
}

virtual int recognize_apprentice(CChar * ob)
{
    if (ob->query("weiwang")<50) return 0;

    return 1;
}


NPC_END;