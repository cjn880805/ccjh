NPC_BEGIN(CNPub_caichanu);

virtual void create()
{
	set_name("�ɲ�Ů","caichanu");

	set("icon", young_woman5);
	set("gender", "Ů��" );
	set("age", 19);
	set("per", 40);
	set("long", "��������Ĳɲ����һ���������ˡ�");
	set("combat_exp", 700);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
	set_skill("parry", 25);
	set_skill("dodge", 30);
	
	set("chat_chance", 5);
	
	add_money(15);
	carry_object("cloth")->wear();
	
};

virtual char * chat_msg(CChar * me)
{
	return "�ɲ�Ů˵����ٯ����ȥ�������㷥������һ��ȥ����ã�";
}

NPC_END;
