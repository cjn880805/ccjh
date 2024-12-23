NPC_BEGIN(CNpub_jianghuyiren);

virtual void create()
{
	set_name("��������","jianghuyiren");

	set("icon", young_man4);
	set("long", "����һ��������Ľ������ˣ�����ǣ��һֻ��˿����������糾֮ɫ.");
	set("gender", "����");
	set("age", 53);
	set("attitude", "friendly");
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);

	set("mp", 400);
	set("max_mp", 400);
	set("mp_factor", 20);
	set("combat_exp", 30000);
	set("score", 10000);

	carry_object("cloth")->wear();

};


NPC_END;
