//pub_zhuoyihang.h
//wuqing 2002-2-10 

NPC_BEGIN(CNpub_zhuoyihang);

virtual void create()
{
	set_name("卓一行","zhun yi hang");
	set("long", "他满脸沧桑，眼中流露悲伤的神情。");
	set("gender", "男性");
	set("age", 80);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",young_man5);	
	set("title","中州一剑");
	set("max_hp", 30000);
	set("mp", 15000);
	set("max_mp", 15000);
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
    set("apply/armor", 340);
	set("apply/damage", 400);
	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
//	carry_object("greyrobe")->wear();
}

virtual char * chat_msg_combat(CChar * player)
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
		if(is_fighting(target)==1 && EQUALSTR(target->querystr_temp("gumu/kill_name"), "卓一行")&& EQUALSTR(target->querystr_temp("gumu/kill_id"), "zhun yi hang"))
		{
			message_vision("\n$N黯然道：你回去告诉百晓生，既然我$N技不如人，从今以后我不再过问他的那些勾当了，太极剑法退出武林谱上排名。", this);
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



