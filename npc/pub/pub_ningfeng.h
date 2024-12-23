//pub_ningfeng.h
//wuqing 2001-12-31

NPC_BEGIN(CNpub_ningfeng);

virtual void create()
{	
	set_name("宁月", "ning yue");
	set("title", "云烟笼阡陌 ");
	set("gender", "女性");
	set("icon", young_woman3);
	set("age", 68);
	set("long",  "她长的极美，其容色晶莹如玉，娇媚不可方物。");
	
	set("str", 65);
	set("int", 65);
	set("con", 65);
	set("dex", 65);
	set("per", 40);
	set("max_hp", 35000);
	set("max_mp", 20000);
	set("mp", 20000);
	set("mp_factor", 150); 
	
	set("combat_exp",  8000000);
	set("chat_chance",  1);
	set("chat_chance_combat", 10);
	
	set_inquiry("峨嵋", "峨嵋自我开山祖师创建至今，就没怕过谁，贫尼。。。");
	set_inquiry("子陵", "相思令人老，奈何堕空门");
	set_inquiry("月庭", "月华满庭。");
	
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 350);
	set_skill("literate", 300);
	set_skill("linji_zhuang", 199);
	set_skill("piaoyibu", 300);
	set_skill("huifeng_qijue", 350);
    
	map_skill("force", "linji_zhuang");
	map_skill("dodge", "piaoyibu");
	map_skill("sword", "huifeng_qijue");
	map_skill("parry", "huifeng_qijue");

	carry_object("changjian")->wield();

}

virtual char * chat_msg()				
{
	switch(random(4))
	{
	case 0:
		return "宁月幽幽的吟起：问世间，情之何物，伤断肠。";
	case 1:
		return "宁CC轻叹道：子陵哥哥不知道可好 ";
	case 2:
		return "宁CC无限伤感道：月华满庭";
	case 3:
		return "宁月仰望着夜空：不知道月庭的兄弟姐妹现在怎么样了？」";
	}
	return 0;
}

virtual char * chat_msg_combat()			
{
	switch(random(2))
	{
	case 0:
		perform_action("sword mixhit", 1);	
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
		if(is_fighting(target)==1 && EQUALSTR(target->querystr_temp("gumu/kill_name"), "宁月")&& EQUALSTR(target->querystr_temp("gumu/kill_id"), "ning yue"))
		{
			message_vision("\n$N黯然道：你回去告诉百晓生，既然我$N技不如人，从今以后我不再过问他的那些勾当了，回风七绝退出武林谱上排名。", this);
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



