//pub_liqiuhen.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_liqiuhen);

virtual void create()
{    
    set_name("李秋痕", "li qiou hen");
    set("long","她、曾经是江湖上的美女，尽管因为年华老去，但风姿不减。。。。");	
    set("gender", "女性"); 
    set("title","碧波仙子");
    set("age", 75);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 40);
    set("icon",young_woman4);

    set("max_hp", 25500);
    set("mp", 18000);
    set("max_mp", 18000);
    set("mp_factor", 400); 
    set("combat_exp", 7000000); 
    set("score", 200000);

    set_skill("force", 350);
    set_skill("beiming_shengong", 350);
    set_skill("dodge", 350);
    set_skill("lingboweibu", 350);
    set_skill("unarmed", 350);
    set_skill("liuyang_zhang", 350);
    set_skill("parry", 350);
    set_skill("blade", 350);
    set_skill("xiaoyao_dao", 350);
    set_skill("zhemei_shou", 350);
    set_skill("hand", 350);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 380);
    set("apply/damage", 200);
    carry_object("gangdao")->wield();

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
		if(is_fighting(target)==1 && EQUALSTR(target->querystr_temp("gumu/kill_name"), "李秋痕")&& EQUALSTR(target->querystr_temp("gumu/kill_id"), "li qiou hen"))
		{
			message_vision("\n$N黯然道：你回去告诉百晓生，既然我$N技不如人，从今以后我不再过问他的那些勾当了，逍遥刀退出武林谱上排名。", this);
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

 



