//qing_le.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_le);

virtual void create()
{
	set_name("清乐比丘", "qingle biqiu");
	set("long",	"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",95);
	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
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
	set_skill("claw", 30);
	set_skill("yingzhua_gong", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("claw", "yingzhua_gong");
	map_skill("parry", "yingzhua_gong");

	prepare_skill("claw", "yingzhua_gong");

	create_family("少林派", 40, "弟子");
	set_inquiry("手谕", ask_me_1);
	set_inquiry("达摩令", ask_me_2);

	carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

static char * ask_me_1(CNpc * npc, CChar * me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "少林派"))
		return "你与本派素无来往，不知此话从何谈起？";

    if ( me->query("guilty") > 0 )
		return 	"你累犯数戒，身带重罪，我如何能给你这手谕！";

    if ( me->query_int() < 30 )
		return 	"资质不够，不能进入藏经楼。";
	
	if( me->mini_skill() < 50) 
		return  "你功力不够，不够资格领取手谕。";
	
    if ( me->query_skill("buddhism",1) < 80 )
		return 	"想学习上乘武功，先要以高深佛法化解它们的戾气。";

	load_item("allow_letter")->move(me);
	message_vision("$N获得一封手谕。", me);

	return "好吧，凭这封手谕，你可自由进入藏经阁二楼研习上乘武功。";

}

static char * ask_me_2(CNpc * npc, CChar * me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "少林派"))
		return 	"你与本派素无来往，不知此话从何谈起？";

	if( me->mini_skill() < 30) 
		return 	"你功力不够，不能领取达摩令。";
	
	load_item("damo_ling")->move(me);
	message_vision("$N获得一面达摩令。", me);

	return "好吧，凭这面达摩令，你可自由向你的师尊挑战。";
}


NPC_END;
