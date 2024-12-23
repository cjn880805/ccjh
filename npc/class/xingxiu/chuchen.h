//chuchen.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxingxiu_chuchen);

virtual void create()
{
	set_name("�볾��", "ruchen zi");
	set("nickname", "�����ɰ�ʦ��");
	set("long","�����Ƕ�����İ˵����볾�ӡ�����Ű��֣��������յĸ����ֳ����ء�");
	set("gender", "����");
	set("age", 25);
	set("icon",young_man3);
	
	set("attitude", "peaceful");
	set("shen_type", -10);
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	set("icon",young_man6);
	
	set("max_hp", 900);
	set("mp", 800);
	set("max_mp", 800);
	set("mp_force", 15);
	set("combat_exp", 100000);
	set("score", 20000);
	
        set_skill("throwing", 60);
	set_skill("feixing_shu", 60);        
	set_skill("force", 60);
	set_skill("huagong_dafa", 40);
	set_skill("dodge", 60);
	set_skill("zhaixinggong", 50);
	set_skill("strike",50);
	set_skill("xingxiu_duzhang", 20);
	set_skill("parry", 50);
	set_skill("staff", 80);
  	set_skill("tianshan_zhang", 80);
   	set_skill("claw", 80); 	
	set_skill("sanyin_wugongzhao", 75);  	
//	set_skill("literate", 50);
	set_skill("poison", 40);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu_duzhang");
  	map_skill("parry", "tianshan_zhang");
  	map_skill("staff", "tianshan_zhang");
  	map_skill("claw", "sanyin_wugongzhao");
  	
	prepare_skill("strike", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");
	create_family("������", 2, "����");

  	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
}

virtual void init(CChar * player)
{
        CNpc::init(player);
        if (userp(player) && !is_fighting())
		{
                if ((DIFFERSTR(player->querystr("family/family_name"), "������")) && !wizardp(player) )
				{
					kill_ob(player);
                }
        }
}

virtual void attempt_apprentice(CChar * player)
{
	say("���ɻ�û��������ͽ�ء�",player);
	SendMenu(player);
}


NPC_END;