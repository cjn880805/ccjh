// zu.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_zu);

virtual void create()
{
	set_name("�����", "zu qianqiu");
	set("nickname", "�ƺ�����");
	set("gender", "����" );
	set("age", 52);
	set("long", 
		"һ���������͵�����������������Ƥ��һ������ǣ����������\n"
		"�������ӣ���������������һƬ�͹⣬��������һ�������ȡ�\n");
	
	set("combat_exp", 100000);
	set("attitude", "friendly");
	
	set("hp",500);
	set("max_hp",500);
	set("per", 17);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("icon",old_man2);
	
	set_skill("literate", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	
//	add_money("gold", 1);
	carry_object("cloth")->wear();
}

NPC_END;