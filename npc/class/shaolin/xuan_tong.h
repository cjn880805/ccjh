//xuan_tong.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_xuan_tong);

virtual void create()
{
	set_name("玄痛大师", "xuantong dashi");
	set("long",	"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材高大，两手过膝。双目半睁半闭，却不时射出一缕精光。");
	
	set("nickname", "戒律院主持");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",106);
	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_hp", 10500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);

	set("combat_exp", 800000);
	set("score", 800000);

//before the modification, all the skills are 140
	set_skill("force", 140);
	set_skill("hunyuan_yiqi", 140);
	set_skill("dodge", 140);
	set_skill("shaolin_shenfa", 140);
	set_skill("parry", 140);
	set_skill("hand", 140);
	set_skill("claw", 140);
	set_skill("club", 210);
	set_skill("staff", 140);
	set_skill("zui_gun", 200);
	set_skill("pudu_zhang", 140);
	set_skill("qianye_shou", 140);
	set_skill("yingzhua_gong", 140);
	set_skill("buddhism", 140);
	set_skill("literate", 140);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	//map_skill("finger", "nianhua_zhi");
	map_skill("hand", "qianye_shou");
	map_skill("claw", "yingzhua_gong");
	map_skill("staff", "pudu_zhang");
	map_skill("club", "zui_gun");
	map_skill("parry", "yingzhua_gong");

	prepare_skill("hand", "qianye_shou");

	create_family("少林派", 36, "弟子");

	set("chat_chance_combat", 45);
	carry_object("jiasha")->wear();
};

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		perform_action("finger fuxue", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if ( DIFFERSTR(me->querystr("family/family_name"), "少林派"))
	{
		say("你与本派素无来往，不知此话从何谈起？", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "少林派")) 
	{
		say("你是俗家弟子，不能在寺内学艺。", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

	char prename[3];
	strncpy(prename, me->name(1), 2)[2]=0;
	if ( (me->query("family/generation") == query("family/generation") + 1) 
		&& strcmp(prename, "澄") == 0)
	{
		say(snprintf(msg, 255, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	}
	else
	{
		say("你辈份不合，不能越级拜师。", me);
		SendMenu(me);
		return;
	}

	return;
}

NPC_END;
