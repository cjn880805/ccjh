// yinchang_gaolaozhe.c

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_gaolaozhe);

virtual void create()
{
	set_name("高人", "gao laozhe");
	set("title", "华山第十二代长老");
	set("long", "他就是华山的雪姑七友中的高人。一副浑不在乎的模样，开朗乐天，万事不萦怀，但事事追随他的师兄矮人。");
	set("gender", "男性");
	set("age", 65);

        set("icon",old_man1);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("hp", 3800);
	set("max_hp", 12000);
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 100);
	
	set("combat_exp", 1250000);
	set("score", 200000);
	
	set_skill("cuff", 170);
	set_skill("force", 160);
	set_skill("blade", 170);
	set_skill("sword", 170);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	set_skill("strike", 170);
	set_skill("zixia_shengong", 150);
	set_skill("poyu_quan", 160);
	set_skill("fanliangyi_dao", 170);
	set_skill("huashan_sword", 170);
	set_skill("hunyuan_zhang", 160);
	set_skill("feiyan_huixiang",160);
	set_skill("literate", 100);
	
	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "feiyan_huixiang");
	map_skill("parry", "fanliangyi_dao");
	map_skill("blade", "fanliangyi_dao");
	map_skill("sword", "huashan_sword");
	map_skill("strike", "hunyuan_zhang");
	
	create_family("华山派", 12, "弟子");
	
	set("chat_chance_combat", 60);
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("blade sanshen", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

NPC_END;