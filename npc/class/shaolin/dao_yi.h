//dao_yi.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_dao_yi);

virtual void create()
{
	set_name("道一禅师", "daoyi chanshi");
	set("long",	"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",113);
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
	set_skill("cuff", 50);
	set_skill("jingang_quan", 50);
	set_skill("parry", 50);
	set_skill("damo_jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");

	prepare_skill("cuff", "jingang_quan");

	create_family("少林派", 39, "弟子");
    carry_object("xu_cloth")->wear();
};

NPC_END;
