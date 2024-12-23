//tianmen.h
//Cat
//2001-02-27
//天门门主

MINGJIAOMENZHU_BEGIN(CNmingjiao_tianmen);

virtual void create()
{
	set_name("天高", "tian gao");
	
	set("title", "天字门门主");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("icon",young_man3);
	create_family("明教",38, "门主");
	set_weight(50000000);

	CMapping par;

	par.set("level", 2);
	set("party", par);

	set("age", 22);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1450);
	set("hp", 1450);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 50);
	set("combat_exp", 50000);
	set("score", 800);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
    set_skill("unarmed", 50);
	set_skill("sword", 70);
	set_skill("literate", 50);
	set_skill("shenghuo_shengong", 50);
	set_skill("shenghuo_xinfa", 50);
	set_skill("piaoyibu", 50);
	
    map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	
	carry_object("baipao")->wear();
	carry_object("changjian")->wield();
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

MINGJIAOMENZHU_END;



