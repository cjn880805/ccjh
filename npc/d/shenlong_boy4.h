// shenlong_boy4.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNshenlong_boy4);

virtual void create()
{
	set_name("年轻弟子", "young boy");
	set("title","神龙教""青龙使""座下弟子");
	set("long","这是一个神龙教弟子，一袭青衣，混身透着一股邪气。 ");
	
	set("gender", "男性");
	set("attitude", "peaceful");
 	set("icon",young_man3);
	
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
	set_skill("sword", 60);
	set_skill("shedao_qigong", 30);
	map_skill("sword","shedao_qigong");
	set("chat_chance", 3);
	carry_object("duanjian")->wield();
	carry_object("xionghuang")->wield();
        carry_object("cloth")->wear();
}
virtual char * chat_msg()
{
	switch (random(5))
	{
	case 0:
		return "年轻弟子说道：教主宝训,时刻在心,建功克敌,无事不成! ";
	case 1:
		return "年轻弟子说道：众志齐心可成城,威震天下无比伦! ";
	case 2:
		return "年轻弟子说道：神龙飞天齐仰望,教主声威盖八方! ";
	case 3:
		return "年轻弟子说道：乘风破浪逞英豪,教主如同日月光! ";
	case 4:
		return "年轻弟子说道：教主永享仙福,寿与天齐! ";
	}
	return "";
}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("usedgao"))          
			unconcious();
	}
	return "";
}
NPC_END;