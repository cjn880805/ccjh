//pub_shuiyunyan.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_shuiyunyan);

virtual void create()
{    
    set_name("水云烟", "shui yun yan");
    set("long","长的天香国色，唯有秀丽的双眉间透露着淡淡的忧愁。。");	
    set("gender", "女性"); 
    set("title","凌波仙子");
    set("age", 33);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 38);
    set("icon", young_woman2);

    set("hp",38500);
	set("max_hp", 38500);
    set("mp", 18000);
    set("max_mp", 18000);
    set("mp_factor", 200); 
    set("combat_exp", 7000000); 
    set("score", 200000);

    set_skill("force", 350);
    set_skill("bahuang_gong", 350);
    set_skill("dodge", 350);
    set_skill("yueying_wubu", 350);
    set_skill("unarmed", 350);
    set_skill("liuyang_zhang", 350);
    set_skill("parry", 350);
    set_skill("sword", 350);
    set_skill("tianyu_qijian", 350);
    set_skill("zhemei_shou", 350);
    set_skill("hand", 350);
    
    map_skill("force", "bahuang_gong");
    map_skill("dodge", "yueying_wubu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "tianyu_qijian");
    map_skill("sword", "tianyu_qijian");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 340);
    set("apply/damage", 400);
    
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
		if(is_fighting(target)==1 && EQUALSTR(target->querystr_temp("gumu/kill_name"), "水云烟")&& EQUALSTR(target->querystr_temp("gumu/kill_id"), "shui yun yan"))
		{
			message_vision("\n$N黯然道：你回去告诉百晓生，既然我$N技不如人，从今以后我不再过问他的那些勾当了，天羽奇剑退出武林谱上排名。", this);
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




