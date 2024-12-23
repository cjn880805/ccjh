//zhaixing.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxingxiu_zhaixing);

virtual void create()
{
	set_name("ժ����", "zhaiyue zi");
	set("nickname", "�����ɴ�ʦ��");
	set("long","�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�����ʮ���꣬�����������۹���͸��һ˿����֮����");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -10);
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	set("icon",young_man2);
	
	set("max_hp", 3000);
	set("mp", 1800);
	set("max_mp", 1800);
	set("mp_force", 60);
	set("combat_exp", 350000);
	set("score", 50000);
	set("have_zhen",8);
	

	set_skill("force", 80);
	set_skill("huagong_dafa", 80);
	set_skill("dodge", 100);
	set_skill("zhaixinggong", 85);
	set_skill("strike",105);
	set_skill("xingxiu_duzhang", 100);
	set_skill("parry", 70);
	set_skill("staff", 70);
	set_skill("tianshan_zhang", 60);
	set_skill("literate", 70);
	set_skill("feixing_shu", 100);
	set_skill("throwing", 100);   
	set_skill("poison", 80);
	set_skill("sanyin_wugongzhao", 105);	
	set_skill("claw", 105);	


	map_skill("force", "huagong_dafa");
	map_skill("dodge", "feixing_shu");
	map_skill("strike", "xingxiu_duzhang");
	map_skill("parry", "tianshan_zhang");
	map_skill("staff", "tianshan_zhang");
	map_skill("throwing", "feixing_shu");
	map_skill("claw", "sanyin_wugongzhao");
	
	prepare_skill("strike", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");	   
	create_family("������", 2, "����");
	   
	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();

	set_inquiry("���ĵ�",ask_dan);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	char new_name[40];
	
	say(" �ðɣ��Ҿ��������ˡ�", player);
	SendMenu(player);
	
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

virtual void init(CChar * player)
{
	CNpc::init(player);
	if (userp(player) && !is_fighting()) 
	{
		if ((player->query("repute")>10000) && (!wizardp(player)))
		{
			say("���޺����Ƕ����й�֮�أ�");
			kill_ob(player);
		}
	}
}

static char * ask_dan(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "������"))
		return "�㲻���������ɵĵ��ӣ����ܸ��㡣";	
	if(player->query_temp("mark/get_lianxin"))
		return "�㲻�Ǹ��ù��𣿲�Ҫ��ô̰�ĺò��ã�";
	if(npc->query("have_zhen") < 0)
		return "�������ˣ����ĵ��Ѹ���������ͬ���ˡ�";
	
	load_item("lianxindan")->move(player);
	
	player->set_temp("mark/get_lianxin",1);
	npc->add_temp("have_zhen", -1);
	
	message_vision("ժ���Ӹ���$Nһ�����ĵ���", player);
	return "";
}

NPC_END;



