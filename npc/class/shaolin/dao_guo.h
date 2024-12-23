//dao_guo.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_dao_guo);

virtual void create()
{
	set_name("������ʦ", "daoguo chanshi");
	set("long",	"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ��У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�");
	
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",81);
	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1200);
	
	set("mp", 450);
	set("max_mp", 450);
	set("mp_factor", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("damo_jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");

	prepare_skill("strike", "banruo_zhang");

	create_family("������", 39, "����");
/*
	set("inquiry", ([
		"ľ��"     : (: ask_me :),
		"����"	   : (: ask_me :),
		"��ľ��"   : (: ask_me :)
	]));
*/
	carry_object("changjian")->wield();
    carry_object("xu_cloth")->wear();
};

NPC_END;
