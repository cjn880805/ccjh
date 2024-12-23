//dao_xiang2.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_dao_xiang2);

virtual void create()
{
	set_name("道象禅师", "daoxiang chanshi");
	set("long",	"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。");

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",118);
	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1200);
	
	set("mp", 450);
	set("max_mp", 450);
	set("mp_factor", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo_zhang", 50);
	set_skill("damo_jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry",  "banruo_zhang");

	prepare_skill("strike", "banruo_zhang");

	create_family("少林派", 39, "弟子");

	set_inquiry("金创药", ask_me_1);
	set_inquiry("小还丹", ask_me_2);
		
	set("jin_count", 2);
	set("xiao_count",1);
	set("da_count",  1);

	carry_object("xu_cloth")->wear();
};

static char * ask_me_1(CNpc * me, CChar * who)
{
	if (DIFFERSTR(who->querystr("family/family_name"), "少林派"))
			return "你与本派素无来往，不知此话从何谈起？";

	if ( who->query_condition("bonze_drug" ) > 0 )
		return "你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if ( who->PresentName("jinchuang_yao", IS_ITEM) )
		return "你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";

	if (me->query("jin_count") < 1) return "对不起，金创药已经发完了";

	load_item("jinchuang_yao")->move(who);
	me->add("jin_count", -1);

	message_vision("$N获得一包金创药。", who);
	return "好吧，记住，不到危急关头不要轻易使用此药。";
}

static char * ask_me_2(CNpc * me, CChar * who)
{
	if ( DIFFERSTR(who->querystr("family/family_name"), "少林派"))
		return 	"你与本派素无来往，不知此话从何谈起？";

	if ( who->query_condition("bonze_drug" ) > 0 )
		return 	"你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if ( who->PresentName("xiaohuan_dan", IS_ITEM) )
		return 	"你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";

	if ( me->query("xiao_count") < 1) return "对不起，小还丹已经发完了";

	load_item("xiaohuan_dan")->move(who);
	me->add("xiao_count", -1);

	message_vision("$N获得一颗小还丹。", who);
	return "好吧，记住，不到危急关头不要轻易使用此药。";
}

NPC_END;
