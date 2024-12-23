// boy.c
//code by sound
//2001-07-12

NPC_BEGIN(CNshenlong_boy);

virtual void create()
{
	set_name("年轻弟子", "young boy");
 	set("icon",young_man2);
	set("title","神龙教黄龙使座下弟子");
	set("long", "这是一个神龙教弟子，一袭黄衣，混身透着一股邪气。");
	
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 200);
	set("hp", 200);
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

	carry_object("xionghuang")->wield();
	carry_object("duanjian")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()						//NPC自动聊天
{
	switch(random(5))
	{
	case 0:
		return 	"年轻弟子忽然高声叫道:教主宝训,时刻在心,建功克敌,无事不成！”";
	case 1:
		return 	"年轻弟子忽然齐声叫道:众志齐心可成城,威震天下无比伦！";
	case 2:
		return 	"年轻弟子忽然齐声叫道:神龙飞天齐仰望,教主声威盖八方！";
	case 3:
		return 	"年轻弟子忽然齐声叫道:乘风破浪逞英豪,教主如同日月光！";
	case 4:
		return 	"年轻弟子齐声叫道:教主永享仙福,寿与天齐！";
	}
	
	return 0;
}
/*
void init()
{
	object ob;
	
	::init();
	
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))          
			unconcious();
	}
	return;
}
*/
NPC_END;