NPC_BEGIN(CNPub_fuer);

virtual void create()
{
	set_name("������","fuer");
	
	set("icon", young_man4);
	set("gender", "����" );
	set("age", 45);
	set("str", 16);
	set("con", 24);
	set("dex", 21);
	set("per", 17);
	set("int", 14);
	set("long", "����������ٹȵ����ˡ�");
	set("attitude", "friendly");
	
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
	
	set("combat_exp", 5000);
	
	set_skill("unarmed", 30);
	set_skill("parry", 40);
	set_skill("dodge", 50);
	set_skill("force", 50);
	
	carry_object("cloth")->wear();
	carry_object("bu_shoes")->wear();
};

NPC_END;
