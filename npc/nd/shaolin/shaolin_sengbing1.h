// sengbing1.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNshaolin_sengbing1);

virtual void create()
{
	set_name("����ɮ��", "seng bing");
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ����\n"
		"�ֱֳ��У���һϮ�ײ�������ģ��ƺ���һ�����ա�\n");

	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
        set("icon",young_monk);
	set("max_hp", 500);
	set("hp", 500);
	set("mp", 500);
	set("max_mp", 500);
	set("pursuer", 1);
	set("combat_exp", 2000);
	set("score", 1);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("unarmed", 30);
	set_skill("banruo_zhang", 30);
	set_skill("parry", 30);
	set_skill("blade", 30);
	set_skill("cibei_dao", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("unarmed", "banruo_zhang");
	map_skill("parry", "cibei_dao");
	map_skill("blade", "cibei_dao");

	carry_object("jiedao")->wield();
	carry_object("cloth")->wield();
}

/*
void init()
{
	object ob = this_player();
	
	::init();

	if (interactive(ob))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       
}
*/

NPC_END;
