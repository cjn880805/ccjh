// ghost.c
//sound 2001-07-11

NPC_BEGIN(CNgaochang_ghost);

virtual void create()
{
	set_name("�»�Ұ��", "gui");
	set("long",
		"���������������ޣ���翲�����һ����˵�����Ĺ��졣\n"
		"�㿴������ͷ�����⡣\n");
	
	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "bonze");
	
	set("age", 100);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("icon",young_man3);			//������������
	set("max_hp", 500);
	set("hp", 500);
	set("mp", 500);
	set("max_mp", 500);
	set("pursuer", 1);
	set("combat_exp", 2000);
	set("score", 1);
	
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	
//	carry_object("jiedao")->wield();
//	carry_object("cloth")->wield();
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