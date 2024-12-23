//hui_zhen.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_hui_zhen);

virtual void create()
{
	set_name("慧真尊者", "huizhen zunzhe");
	set("long",	"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，太阳穴微凸，双目炯炯有神。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",93);
	set("age", 50);
	set("shen_type", 1);
	set("str", 100000);
	set("int", 30);
	set("con", 30);
	set("dex", 100000);
	set("max_hp", 18000);
	
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 100);
	set_skill("hunyuan_yiqi", 80);
	set_skill("dodge", 80);
	set_skill("shaolin_shenfa", 80);
	set_skill("finger", 90);
	set_skill("yizhi_chan", 90);
	set_skill("strike", 70);
	set_skill("banruo_zhang", 70);
	set_skill("sword", 80);
	set_skill("damo_jian", 80);
	set_skill("parry", 80);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "yizhi_chan");
	map_skill("strike", "banruo_zhang");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");

	prepare_skill("finger", "yizhi_chan");
	prepare_skill("strike", "banruo_zhang");

	create_family("少林派", 38, "弟子");

    carry_object("changjian")->wield();
    carry_object("xu_cloth")->wear();
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		if (! me->querymap("family")) 
			return;

		if( DIFFERSTR(me->querystr("family/family_name"), "少林派"))
		{
			say("大胆狂徒，竟敢杀人闯入藏经阁，看招!");
			kill_ob(me); 
		}
	}
}

NPC_END;
