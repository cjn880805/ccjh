//tuoba.h
//Lanwood
//2001-01-09

MINGJIAOMENZHU_BEGIN(CNmingjiao_tuoba);

virtual void create()
{
	set_name("风啸", "feng xiao");
	set("long", "他是一位带发修行的头陀，身穿一件白布长袍。他个子不高，但很结实，看上去颇为纯朴。可是脸上经常浮现出奇怪的笑容，让人有些摸不着头脑。");
	
	set("title", "风字门门主");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
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
	set_skill("strike", 70);
	set_skill("literate", 50);
	set_skill("shenghuo_shengong", 50);
	set_skill("shenghuo_xinfa", 50);
	set_skill("piaoyibu", 50);
	
    map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	
	carry_object("baipao")->wear();
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



