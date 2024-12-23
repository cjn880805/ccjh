//pub_gongsun_zhi.h
//wuqing 03.05

NPC_BEGIN(CNpub_gongsunzhi);

virtual void create()
{
	set_name("公孙指","gongsun_zhi");
	set("long", "他长须飘飘神情俊朗，但冰冷的目光让人不寒而栗。");
	set("nickname", "绝情谷主");
	set("gender", "男性");
	set("age", 42);
	set("str", 30);
    set("dex", 35);
	set("con", 37);
	set("int", 35);	
    set("icon",old_man1);
	
	set("hp", 47000);
	set("max_hp", 47000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 100);
	set("no_kill",1);
	
	set("combat_exp", 10000000);
	
	set_skill("force", 350);
	set_skill("beiming_shengong", 350);    
	set_skill("blade", 350);
	set_skill("frost_blade", 350);     
	set_skill("dodge", 350);
	set_skill("guimei_shenfa", 350);   
	set_skill("parry", 350);
	set_skill("unarmed",350);
	set_skill("xianglong_zhang", 400);    
	
	map_skill("force", "beiming_shengong");
	map_skill("blade", "frost_blade");
	map_skill("dodge", "guimei_shenfa");
	map_skill("parry", "xianglong_zhang");
	map_skill("unarmed", "xianglong_zhang");
	
	prepare_skill("unarmed", "xianglong_zhang");
	set("apply/armor", 300);
    set("apply/damage", 200);
	set("no_kill",1);//不被列入万劫谷的任务中
	
	set_inquiry("龙儿","她是我的柳妹，已经答应嫁给我了，可惜被杨过这个臭小子给抢走了。");
	set_inquiry("过儿","哼，我迟早会出去找他去算这笔帐的。");
	set_inquiry("情花","中了情花的毒只有绝情丹才能医。");
	set_inquiry("绝情丹",ask_me);
	
	carry_object("gangdao")->wield();
//	carry_object("junqing_dan", 1);

}

static char * ask_me(CNpc * npc , CChar * player)
{
	char msg[255];

	message_vision("公孙指冷笑一声：『凭你也想要绝情丹，打赢我再说。』", player);
	message_vision(snprintf(msg,255,"公孙指决心杀死%s",player->name()),player);
	player->set_temp("gumu/gongsun",1);
    npc->kill_ob(player);
	return "";
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(3))
	{
	case 0:
		perform_action("force recover",0);
		break;
	case 1:
		perform_action("force recover",0);
		break;
	case 2:
		perform_action("force recover",0);
		break;
	}
	return 0;
}

virtual void die()
{
	CContainer * bot;
/*	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		if(is_fighting(target)==1 && target->query_temp("gumu/jq_count")==1 && target->query_temp("gumu/gongsun"))
		{
			message_vision("$HIR小子算你狠，绝情丹拿去吧。", this);
			bot = load_item("mixian");
			bot->set_name("绝情丹", "jue qing dan");
			bot->set("long","四四方方骰子般的丹药，色作深黑，腥臭刺鼻，正使天竺奇花『情花』的独门解药。");
			bot->set("value", 0l);      
			bot->set("unit", "颗");
			bot->move(target);
			target->set_temp("gumu/jq_dan_ok",1);
		}
	}
*/	CChar * target = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(is_fighting(target)==1 && target->query_temp("gumu/jq_count")==1 && target->query_temp("gumu/gongsun"))
	{
		message_vision("$HIR小子算你狠，绝情丹拿去吧。", this);
		bot = load_item("mixian");
		bot->set_name("绝情丹", "jue qing dan");
		bot->set("long","四四方方骰子般的丹药，色作深黑，腥臭刺鼻，正使天竺奇花『情花』的独门解药。");
		bot->set("value", 0l);      
		bot->set("unit", "颗");
		bot->move(target);
		target->set_temp("gumu/jq_dan_ok",1);
	}
	message_vision("公孙指死了。", this);
	destruct(this);
}

NPC_END;

  

           



