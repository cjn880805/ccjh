//tangruei.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_tangruei);

virtual void create()
{
	set_name("唐锐","tangruei");
	
	set("icon", triggerman2);
	set("title","唐门长房弟子");
	set("long","这是一个唐门长房弟子，一袭青衣，浑身透着一股邪气。本月长房轮值。");
	
	
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 600);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 5+random(5));
	set("combat_exp", 20000+random(10000));
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("throwing", 60);
	set_skill("hanxing_bada", 60);
	map_skill("throwing","hanxing_bada");
	map_skill("parry","hanxing_bada");
	carry_object("jili")->wield();
	carry_object("zimuzhen")->wield();
	set("chat_chance", 3);
	
};

virtual char * chat_msg(CChar * me)
{
	return "唐锐说道：江湖中无人敢侵犯唐门!";
}
NPC_END;
