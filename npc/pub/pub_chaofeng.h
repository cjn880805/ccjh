NPC_BEGIN(CNPub_chaofeng);
//inherit F_DEALER;
virtual void create()
{
	set_name("�ϳ���","chaofeng");

	set("icon", pawnshop_boss);
	set("title", "�����ϰ�");
	

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long", "һ�����Ź��ʵ��ϳ��");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");

	carry_object("weibo")->wear();
	carry_object("bluecloth")->wear();
	carry_object("bu_shoes")->wear();

};

virtual void die()
{
	message_vision("$N���ˡ�", this);
	destruct(this);
}

NPC_END;
