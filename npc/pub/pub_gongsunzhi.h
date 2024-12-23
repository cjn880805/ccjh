//pub_gongsun_zhi.h
//wuqing 03.05

NPC_BEGIN(CNpub_gongsunzhi);

virtual void create()
{
	set_name("����ָ","gongsun_zhi");
	set("long", "������ƮƮ���鿡�ʣ��������Ŀ�����˲���������");
	set("nickname", "�������");
	set("gender", "����");
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
	set("no_kill",1);//����������ٹȵ�������
	
	set_inquiry("����","�����ҵ����ã��Ѿ���Ӧ�޸����ˣ���ϧ����������С�Ӹ������ˡ�");
	set_inquiry("����","�ߣ��ҳ�����ȥ����ȥ������ʵġ�");
	set_inquiry("�黨","�����黨�Ķ�ֻ�о��鵤����ҽ��");
	set_inquiry("���鵤",ask_me);
	
	carry_object("gangdao")->wield();
//	carry_object("junqing_dan", 1);

}

static char * ask_me(CNpc * npc , CChar * player)
{
	char msg[255];

	message_vision("����ָ��Цһ������ƾ��Ҳ��Ҫ���鵤����Ӯ����˵����", player);
	message_vision(snprintf(msg,255,"����ָ����ɱ��%s",player->name()),player);
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
			message_vision("$HIRС������ݣ����鵤��ȥ�ɡ�", this);
			bot = load_item("mixian");
			bot->set_name("���鵤", "jue qing dan");
			bot->set("long","���ķ������Ӱ�ĵ�ҩ��ɫ����ڣ��ȳ��̱ǣ���ʹ�����滨���黨���Ķ��Ž�ҩ��");
			bot->set("value", 0l);      
			bot->set("unit", "��");
			bot->move(target);
			target->set_temp("gumu/jq_dan_ok",1);
		}
	}
*/	CChar * target = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(is_fighting(target)==1 && target->query_temp("gumu/jq_count")==1 && target->query_temp("gumu/gongsun"))
	{
		message_vision("$HIRС������ݣ����鵤��ȥ�ɡ�", this);
		bot = load_item("mixian");
		bot->set_name("���鵤", "jue qing dan");
		bot->set("long","���ķ������Ӱ�ĵ�ҩ��ɫ����ڣ��ȳ��̱ǣ���ʹ�����滨���黨���Ķ��Ž�ҩ��");
		bot->set("value", 0l);      
		bot->set("unit", "��");
		bot->move(target);
		target->set_temp("gumu/jq_dan_ok",1);
	}
	message_vision("����ָ���ˡ�", this);
	destruct(this);
}

NPC_END;

  

           



