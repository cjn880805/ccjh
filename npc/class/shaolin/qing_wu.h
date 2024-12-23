//qing_wu.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_wu);

virtual void create()
{
	set_name("清无比丘", "qingwu biqiu");
	set("long",	"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",99);
	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 17);
	set("con", 20);
	set("dex", 24);
	set("max_hp", 1050);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("blade", 30);
	set_skill("cibei_dao", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");

	create_family("少林派", 40, "弟子");

	carry_object("jiedao")->wield();
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if( DIFFERSTR(me->querystr("gender"), "男性") )
	{
		say("阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。", me);
		SendMenu(me);
		return;
	}
	
	if ( EQUALSTR(me->querystr("family/family_name"), "少林派") 
		&& me->query("family/generation") <= query("family/generation") )
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

	if( DIFFERSTR(me->querystr("class"), "bonze") )
		say("阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	else
		say("阿弥陀佛，善哉！善哉！");

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
}

NPC_END;
