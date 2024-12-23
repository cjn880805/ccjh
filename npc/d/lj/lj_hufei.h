// hufei.H
//wq 2001-07-19

NPC_BEGIN(CNlj_hufei);

virtual void create()
{
	set_name("胡飞", "hu fei");
	set("gender", "男性");
	set("title", "雪山飞狐");
	set("age", 25);
	set("long", "他就是胡大刀之子，因其武功高强神出鬼没。在江湖上人送外号「雪山飞狐」。他身穿一件白色长衫，腰间别着一把看起来很旧的刀。他满腮虬髯，根根如铁，一头浓发，却不结辫。");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per",24);
	set("icon",young_man2);	
        	
	set("hp", 20000);
	set("max_hp", 20000);
	set("mp", 5000);
	set("max_mp", 8000);
	set("mp_factor", 100);
	set("combat_exp", 7000000);
	set("shen_type", 1);
	 
	set_skill("force", 250);             
	set_skill("hujia_daofa", 250);      	
	set_skill("hunyuan_yiqi", 250);
	set_skill("blade", 250);             
	set_skill("dodge", 250);             
	set_skill("shaolin_shenfa", 250);    
	set_skill("parry", 250);             
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "hujia_daofa");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");

	set("chat_chance_combat", 30);
	carry_object("blade_1")->wield();
	set("no_kill",1);
}


virtual char * chat_msg_combat()	
{		
	switch(random(3))
	{
	case 0:
		perform_action("blade huanying", 1);
		break;
	case 1:
		perform_action("blade lian", 1);
		break;
	case 2:
		perform_action("blade lian", 1);
		break;
	}	
	return 0;
}

NPC_END;