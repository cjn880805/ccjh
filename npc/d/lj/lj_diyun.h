// diyun.H
//wq 2001-07-19

NPC_BEGIN(CNlj_diyun);

virtual void create()
{
	set_name("����", "di yun");
	set("gender", "����");
	set("title", "���ǽ�");
	set("age", 25);
	set("long", 
		"�����ǵҺ��Ĵ���ӣ������书��ǿ�����û���ڽ�����������š����ǽ�����������ȥ����һ�����µ�ũ��");
	
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",young_man2);	
	set("per",27);

	set("hp", 30000);
	set("max_hp", 30000);
	set("mp", 13000);
	set("max_mp", 13000);
	set("combat_exp", 5900000);
	set("shen_type", 1);
	
	set_skill("force", 300);             
	set_skill("doomsword", 200);      	
	set_skill("hunyuan_yiqi", 300);
	set_skill("sword", 200);             
	set_skill("dodge", 300);             
	set_skill("shaolin_shenfa", 300);    
	set_skill("parry", 300);             
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("sword", "doomsword");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");

	carry_object("sword_1")->wield();
	set("chat_chance_combat", 30);
	set("no_kill",1);

}


virtual char * chat_msg_combat()	
{
	switch(random(2))
	{
	case 0:
		perform_action("sword zhuang", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}	
	return 0;
}

NPC_END;