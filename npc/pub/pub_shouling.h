//shouling.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shouling);

virtual void create()
{
	set_name("��������","shou ling");

	set("icon", triggerman2);
	set("age", 42);
	set("title", "��Դ������");
	set("gender", "����");
	set("long", "����һ�������Ƥ�ĸߴ����ԡ�");
	set("attitude", "peaceful");

	set("str", 34);
	set("per", 16);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 50);
	set_skill("parry", 40);
	set_skill("blade", 80);
	set_skill("force", 40);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("mandao")->wield();
	carry_object("hupi")->wear();

};

NPC_END;
