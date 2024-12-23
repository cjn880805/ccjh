//Lanwood 2000-09-17

FIGHTER_BEGIN(CNwiz_fighter1);

void create()
{
	set_name("武神", "wu shen");

	set("title", "少年组登记员");
		
	set("chname", "武神");
	set("channel", "f1");

	set("wait_time", 10);

	set("grant", 80);
				
	set("judge/attr", "level");
	set("judge/min", 0l);
	set("judge/max", 30);
	set("judge/desc", "等级在30级以下（不含30级）。");

	set("biwu/name", "少年比武大会");
	set("biwu/register/0", "空缺");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

//-------------------------------------------
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",taoist);	
	
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 7000000);
	set("score", 1200000);

	set_skill("force", 320);
	set_skill("taiji_shengong", 320);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 350);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 330);
	set_skill("taiji_jian", 330);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");
	
	set("class", "taoist");

	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	Load();
};

char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}

FIGHTER_END;




