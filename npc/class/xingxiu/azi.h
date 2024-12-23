// azi.c 阿紫
//code by cat
//2001-02-21

NPC_BEGIN(CNxingxiu_azi);

virtual void create()
{
	set_name("阿绿", "alv");
	set("nickname", "星宿派小师妹");
	set("long", "她就是丁老仙的弟子阿绿。她容颜俏丽，可眼神中总是透出一股邪气。");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -10);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_force", 10);
	set("combat_exp", 60000);
	set("score", 10000);

	set("icon",young_woman2);

	set_skill("force", 40);
  	set_skill("huagong_dafa", 25);
	set_skill("dodge", 45);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 45);
	set_skill("claw", 45);	
	set_skill("sanyin_wugongzhao", 45);
	set_skill("xingxiu_duzhang", 40);
	set_skill("parry", 20);
	set_skill("staff", 20);
	set_skill("throwing", 40);
	set_skill("feixing_shu", 40);
//	set_skill("tianshan-zhang", 80);
	set_skill("literate", 40);
	set_skill("poison", 30);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu_duzhang");
	map_skill("parry", "xingxiu_duzhang");
        map_skill("claw", "sanyin_wugongzhao");		
//	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");
	create_family("星宿派", 2, "弟子");

	carry_object("xxqingxin_san");
	carry_object("xxqingxin_san");
	carry_object("cloth")->wear();
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	char new_name[40];

	say(" 好吧，我就收下你了。");
	
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