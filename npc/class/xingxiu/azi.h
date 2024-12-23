// azi.c ����
//code by cat
//2001-02-21

NPC_BEGIN(CNxingxiu_azi);

virtual void create()
{
	set_name("����", "alv");
	set("nickname", "������Сʦ��");
	set("long", "�����Ƕ����ɵĵ��Ӱ��̡�������������������������͸��һ��а����");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -10);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_force", 10);
	set("combat_exp", 60000);
	set("score", 10000);

	set("icon",young_woman2);

	set_skill("force", 40);
  	set_skill("huagong_dafa", 25);
	set_skill("dodge", 45);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 45);
	set_skill("claw", 45);	
	set_skill("sanyin_wugongzhao", 45);
	set_skill("xingxiu_duzhang", 40);
	set_skill("parry", 20);
	set_skill("staff", 20);
	set_skill("throwing", 40);
	set_skill("feixing_shu", 40);
//	set_skill("tianshan-zhang", 80);
	set_skill("literate", 40);
	set_skill("poison", 30);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu_duzhang");
	map_skill("parry", "xingxiu_duzhang");
        map_skill("claw", "sanyin_wugongzhao");		
//	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");
	create_family("������", 2, "����");

	carry_object("xxqingxin_san");
	carry_object("xxqingxin_san");
	carry_object("cloth")->wear();
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	char new_name[40];

	say(" �ðɣ��Ҿ��������ˡ�");
	
    if (DIFFERSTR(player->querystr("family/family_name"), "������")) 
	{
		strcpy(new_name,player->querystr("name"));
		if( strlen(new_name) < 10 &&  strlen(new_name) > 4 )
		{
			strcat(new_name,"��");
			player->set("name",new_name);	
		}
		else
		{
			strncpy(new_name, player->querystr("name"), 8)[8] = 0;
			strcat(new_name,"��");
			player->set_name( new_name);
		}
	}
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

NPC_END;