//da_mo.h
//Lanwood 2000-01-10

ZUSHI_BEGIN(CNshaolin_da_mo);

virtual void create()
{
	set_name("达摩老祖", "da mo");
	set("long",	"他是一位卷发络腮须的天竺老僧，身穿一袭邋遢金丝绣红袈裟。但却满面红光，目蕴慈笑，眼现智珠，一派得道高僧气势。");
	
	set("title", "少林开山祖师");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",119);
	set("age", 80);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("hp",35000);
	set("max_hp", 35000);
	set("mp",18000);
	set("max_mp", 18000);
	set("mp_factor", 250);
	set("combat_exp", 60000000);
	set("score", 500000);

	set_skill("buddhism", 280);
	set_skill("literate", 230);

	set_skill("blade", 300);
	set_skill("claw", 300);
	set_skill("club", 400);
	set_skill("cuff", 300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("hand", 300);
	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("whip", 300);

	set_skill("banruo_zhang", 300);
	set_skill("cibei_dao", 300);
	set_skill("damo_jian", 300);
	set_skill("fengyun_shou", 300);
	set_skill("fumo_jian", 300);
	set_skill("hunyuan_yiqi", 300);
	set_skill("jingang_quan", 300);
	set_skill("longzhua_gong", 300);
	set_skill("luohan_quan", 300);
	set_skill("nianhua_zhi", 300);
	set_skill("pudu_zhang", 300);
	set_skill("qianye_shou", 300);
	set_skill("sanhua_zhang", 300);
	set_skill("riyue_bian", 300);
	set_skill("shaolin_shenfa", 300);
	set_skill("weituo_gun", 300);
	set_skill("wuchang_zhang", 300);
	set_skill("xiuluo_dao", 300);
	set_skill("yingzhua_gong", 300);
	set_skill("yijinjing", 350);
	set_skill("yizhi_chan", 300);
	set_skill("zui_gun", 300);

	map_skill("blade", "cibei_dao");
	map_skill("claw", "longzhua_gong");
	map_skill("club", "wuchang_zhang");
	map_skill("cuff", "luohan_quan");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun_shou");
	map_skill("parry", "nianhua_zhi");
	map_skill("staff", "weituo_gun");
	map_skill("strike", "sanhua_zhang");
	map_skill("sword", "fumo_jian");
	map_skill("whip", "riyue_bian");

	prepare_skill("finger", "nianhua_zhi");
	prepare_skill("strike", "sanhua_zhang");

	create_family("少林派", 34, "弟子");
	carry_object("xuan_cloth")->wear();

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "少林派"))
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

	if ( me->query("family/generation") != 36 )
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

    if ((me->query_int() < 40) || (me->query("pks") > 10 )) 
    {
        say("万事都讲一个缘字。", me);
        say("你与佛无缘，还是请回吧。", me);
		SendMenu(me);
		return;
	}

	if (me->query_skill("dodge",1)>=150 &&
		me->query_skill("force",1)>=150 &&
		me->query_skill("parry",1)>=150 &&
		me->query_skill("buddhism",1)>=150)
	{
		char new_name[5], myname[5];
		strncpy(myname, me->name(), 4)[4] = 0;
		strcpy(new_name, "渡");
		new_name[2] = myname[2];
		new_name[3] = myname[3];
		new_name[4] = 0;

		me->set_name( new_name);
		me->set("family/generation", 36);

		say("老衲又得一可塑之才，真是大畅老怀 !");
		say(snprintf(msg, 255, "从今以后你的法名叫做%s，恭喜你荣升为少林派渡字辈弟子 !", new_name));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));	
	}
	else
	{
		say("你现在就来找我也太早了点吧 !", me);
		SendMenu(me);
	}	
}

ZUSHI_END;
