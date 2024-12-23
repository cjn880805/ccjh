// shuidai.c

//code by sound
//date:2001-07-11

NPC_BEGIN(CNxuedao_shuidai);

virtual void create()
{
	set_name("ˮ��", "shui dai");
	set("long", 
		"�����������桰�仨��ˮ���е����ġ�\n"
		"��������н��ϣ��������壬�主�׶��ϣ�����ȴ������ɫ��\n");
	set("gender", "����");
	set("nickname", "���½�");
	set("age", 39);
	set("attitude", "peaceful");
	set("shen_type", 0l);
	set("str", 35);
	set("int", 38);
	set("con", 35);
	set("dex", 35);
	set("icon",young_man5);
	
	set("max_hp", 2000);
	set("hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 30);
	set("combat_exp", 800000);
	set("shen_type", 1);
	
	set_skill("force", 100);
	set_skill("zixia_shengong", 100);
	set_skill("dodge", 100);
	set_skill("huashan_shenfa", 100);
	set_skill("strike", 100);
	set_skill("hunyuan_zhang", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("huashan_sword", 100);
	set_skill("literate", 80);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("strike", "hunyuan_zhang");
	map_skill("parry", "huashan_sword");
	map_skill("sword", "huashan_sword");
	
	set("chat_chance", 20);
	
	carry_object("changjian")->wield();
}

virtual char * chat_msg()
{
	return "ˮ������������Х����磺���仨��ˮ�������������ƾ�����ԶԶ������";
}

NPC_END;