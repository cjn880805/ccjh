//menwei1.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_menwei1);

virtual void create()
{
	set_name("����1","menwei");

	set("icon", young_man1);
	set("gender", "����" );

	set("age", 35);
	set("long", "���̵�������ʿ�����һ������¡�");
	set("shen_type",1);
	set("combat_exp", 20000);

	set("attitude", "peaceful");

	set("apply/attack", 50);
	set("apply/defense", 50);


	set_skill("unarmed", 50);
	set_skill("parry", 40);
	set_skill("dodge", 50);

	carry_object("cloth")->wear();
	add_money(20);

};

NPC_END;
