//huangyu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_huangyu);

virtual void create()
{
	set_name("����","huangyu");

	set("icon", pawnshop_boss);
	set("title", "�����ϰ�");
	set("nickname", "�ϻ�ͷ");
	

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 55);
	set("str", 100);
	set("long", "һ���ϼ��̣���Ҫ�����ˣ�");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();

};

void die()
{
	message_vision("$N���ˡ�", this);
	destruct(this);
}

NPC_END;
