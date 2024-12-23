// shaolin_gaoyanch.c 高彦超

//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_gaoyanch);

virtual void create()
{
	set_name("高霜过",  "gao yanchao");
	set("title",  "天地会青木堂会众");
	set("gender", "男性");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("long", "他不过三十出头，却显得异常老练。一言不发地往那儿一站，真是威风凛凛。");
	set("combat_exp", 40000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
        set("icon",young_man1);
	
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("club", 80);
	set_skill("parry", 70);
	set_skill("literate", 50);
	set_skill("hunyuan_yiqi", 60);
	set_skill("shaolin_shenfa", 60);
	set_skill("zui_gun", 70);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("club", "zui_gun");
	map_skill("parry", "zui_gun");
	
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 25);
	set("hp", 400);
	set("max_hp", 1200);
	set("mp", 250); 
	set("max_mp", 250);
	set("mp_factor", 35);

	set_inquiry("陈远北","想见总舵主可不容易啊。");
	set_inquiry("天地会","只要是英雄好汉，都可以入我天地会(join tiandihui)。");
	set_inquiry("入会","只要入了我天地会，可以向会中各位好手学武艺。");
	set_inquiry("反清复明","去棺材店内室仔细瞧瞧吧！");
	set_inquiry("暗号","敲三下！");
	set_inquiry("江湖威望",ask_weiwang);
 	
	carry_object("qimeigun")->wield();
	carry_object("cloth")->wear();
	add_money( 1000);
}

static char * ask_weiwang(CNpc *who ,CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"你现在的江湖威望是%ld",me->object_id(),me->query("weiwang") ), me);
	who->say("如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。", me);
	who->say("杀某些坏人或救某些好人可以提高江湖威望。", me);
	who->SendMenu(me);
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
virtual int recognize_apprentice(CChar * ob)
{
    if (ob->query("weiwang")<50)
		return 0;

	return 1;
}

int do_skills(CChar *ob,char * arg)
{
	char msg[255];
	if( !arg || arg!="gao" )
		return 0;
	if(wizardp(ob)) return 0;
	if (DIFFERSTR(ob->querystr("party/party_name"), "天地会")  )
	{
		message_vision("$N摇了摇头。",this);
		command(snprintf(msg,255,"tell %ld  不是天地会弟子不能察看。",ob->object_id() )); 
		return 1;
	}
	
	//command(snprintf(msg,255,"tell %ld  我所有的武功如下：   基本棍法 (club)  - 登峰造极  80/       基本轻功 (dodge)  - 出神入化  70/       基本内功 (force)  - 出神入化  70/     □混元一气功 (hunyuan_yiqi)  - 神乎其技  60/       读书写字 (literate)  - 心领神会  50/       基本招架 (parry) - 出神入化  70/     □少林身法 (shaolin_shenfa) - 神乎其技  60/       基本拳脚 (unarmed) - 出神入化  70/     □少林醉棍 (zui_gun) - 出神入化  70/    ",ob->object_id() ));
	return 1;
}

NPC_END;