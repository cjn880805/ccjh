// pub_shi.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_shi);


virtual void create()
{
	set_name("ʩ��", "shi en" );

	set("icon", pub_boss);
	set("long",	"���������ӽ�������Ľ��۱�ʩ����������÷ׯ���ܼҡ�");
	
	set("gender", "����");
	set("nickname", "���۱�");
	set("attitude", "friendly");
	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_hp", 10050);
	set("mp", 1350);
	set("max_mp", 1350);
	set("mp_factor", 100);
	set("combat_exp", 300000);
	set("score", 100);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);
	
	create_family("÷ׯ", 3, "����");
	set("chat_chance", 10);
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}

virtual char * chat_msg()
{
	return "ʩ��������ŵĳ����Ӻ�������һ�ۡ�";
}

NPC_END;