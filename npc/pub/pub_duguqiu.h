//pub_duguqiu.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_duguqiu);

virtual void create()
{
	set_name("独孤求", "du gu qiu");

	set("long", "他是天下闻名的剑客，但是他总是愁眉不展，不知道在想念着谁。。");

	set("gender", "男性");
	set("age", 68);
    set("attitude", "peaceful");	
    set("str", 60);
	set("int", 50);
	set("con", 55);
	set("dex", 65);
	set("icon",old_man1);
	
	set("hp", 38500);
	set("max_hp", 38500);
	
	set("mp", 15500);
	set("max_mp", 15500);
	set("mp_factor", 200);

	set("combat_exp", 7000000);
	set("score", 500000);

	set_skill("cuff", 350);
	set_skill("force", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("sword", 350);
	set_skill("strike",350);
	set_skill("unarmed", 350);
	set_skill("zixia_shengong", 350);
	set_skill("poyu_quan", 350);
	set_skill("huashan_sword", 350);
	set_skill("hunyuan_zhang", 350);
	set_skill("lonely_sword", 350);
	set_skill("huashan_shenfa",350);
	set_skill("literate", 320);
	set_skill("zhengqijue", 350);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	map_skill("strike", "hunyuan_zhang");

		
	set("apply/armor", 340);
	set("apply/damage", 400);
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();

	set("no_get", 1);
};

char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("sword poqi", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

virtual void die()
{
	CContainer * obj = environment();
	char msg[255];
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		if(is_fighting(target)==1 && EQUALSTR(target->querystr_temp("gumu/kill_name"), "独孤求")&& EQUALSTR(target->querystr_temp("gumu/kill_id"), "du gu qiu"))
		{
			message_vision("\n$N黯然道：你回去告诉百晓生，既然我$N技不如人，从今以后我不再过问他的那些勾当了，独孤九剑退出武林谱上排名。", this);
			target->delete_temp("gumu/kill_name");
			target->delete_temp("gumu/kill_id");
			target->add("combat_exp",target->query_temp("gumu/kill_exp"));
			message_vision(snprintf(msg, 255, "$HIR$N获得了%d的任务经验奖励。\n",target->query_temp("gumu/kill_exp")), target);
			target->delete_temp("gumu/kill_exp");
			target->add_temp("gumu/jq_renwu",1);
			continue;
		}
	}
	CNpc::die();
}

NPC_END;




