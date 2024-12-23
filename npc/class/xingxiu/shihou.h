// shihou.c 狮吼子
//code by cat
//2001-02-21

NPC_BEGIN(CNxingxiu_shihou);

virtual void create()
{
	set_name("狮叫子", "shijiao zi");
	set("nickname", "星宿派二师兄");
	set("long", "他就是丁春秋的二弟子狮叫子。他三十多岁，狮鼻阔口，一望而知不是中土人士。");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -10);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_hp", 1500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_force", 20);

	set("icon",young_man1);

	set("combat_exp", 200000);
	set("score", 30000);
	
        set_skill("throwing", 80);
        set_skill("feixing_shu", 80);
	set_skill("claw", 85);    
	set_skill("force", 80);
	set_skill("huagong_dafa", 70);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 40);
	set_skill("strike",70);
	set_skill("xingxiu_duzhang", 40);
	set_skill("parry", 60);
	set_skill("staff", 90);
  	set_skill("tianshan_zhang", 80);
	set_skill("sanyin_wugongzhao", 70);
	set_skill("claw", 70);
//	set_skill("literate", 50);
	set_skill("poison", 60);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu_duzhang");
  	map_skill("parry", "tianshan_zhang");
  	map_skill("staff", "tianshan_zhang");
	map_skill("claw", "sanyin_wugongzhao");
	prepare_skill("strike", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");

	create_family("星宿派", 2, "弟子");

  	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	char new_name[40];

	say(" 好吧，我就收下你了。",player);
	SendMenu(player);
    if (DIFFERSTR(player->querystr("family/family_name"), "星宿派")) 
	{
		strcpy(new_name,player->querystr("name"));
		if( strlen(new_name) < 10 &&  strlen(new_name) > 4 )
		{
			strcat(new_name,"子");
			player->set("name",new_name);	
		}
		else
		{
			strncpy(new_name, player->querystr("name"), 8)[8] = 0;
			strcat(new_name,"子");
			player->set_name( new_name);
		}
	}
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

NPC_END;