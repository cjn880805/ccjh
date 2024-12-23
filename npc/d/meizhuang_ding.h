// meizhuang_ding.c
//code by Fisho
//date:2000-12-21
//inherit F_CLEAN_UP;

NPC_BEGIN(CNmeizhuang_ding);

virtual void create()
{
	set_name("����", "ding jian");
	set("long","���������ӽ�������Ļ��ε罣���ᣬ������÷ׯ���ܼҡ�");
	set("gender", "����");
	set("nickname", "���ε罣");
	set("attitude", "friendly");
 	set("icon",old_man2);
	
	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_hp", 3350);
	set("hp",  3350);
	set("mp", 1350);
	set("max_mp", 1350);
	set("mp_factor", 1);
	set("combat_exp", 100000);
	set("score", 100);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);
	
	create_family("÷ׯ", 2, "����");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();

}

NPC_END;