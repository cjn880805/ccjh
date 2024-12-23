// hufei.H
//wq 2001-07-19

NPC_BEGIN(CNlj_hufei);

virtual void create()
{
	set_name("����", "hu fei");
	set("gender", "����");
	set("title", "ѩɽ�ɺ�");
	set("age", 25);
	set("long", "�����Ǻ���֮�ӣ������书��ǿ�����û���ڽ�����������š�ѩɽ�ɺ���������һ����ɫ�������������һ�ѿ������ܾɵĵ�����������ף�����������һͷŨ����ȴ����衣");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per",24);
	set("icon",young_man2);	
        	
	set("hp", 20000);
	set("max_hp", 20000);
	set("mp", 5000);
	set("max_mp", 8000);
	set("mp_factor", 100);
	set("combat_exp", 7000000);
	set("shen_type", 1);
	 
	set_skill("force", 250);             
	set_skill("hujia_daofa", 250);      	
	set_skill("hunyuan_yiqi", 250);
	set_skill("blade", 250);             
	set_skill("dodge", 250);             
	set_skill("shaolin_shenfa", 250);    
	set_skill("parry", 250);             
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "hujia_daofa");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");

	set("chat_chance_combat", 30);
	carry_object("blade_1")->wield();
	set("no_kill",1);
}


virtual char * chat_msg_combat()	
{		
	switch(random(3))
	{
	case 0:
		perform_action("blade huanying", 1);
		break;
	case 1:
		perform_action("blade lian", 1);
		break;
	case 2:
		perform_action("blade lian", 1);
		break;
	}	
	return 0;
}

NPC_END;