//xier.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xier);

virtual void create()
{
	set_name("��ϲ��","xier");
	
	set("icon", young_woman6);
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 16);
	set("con", 24);
	set("dex", 11);
	set("per", 17);
	set("int", 14);
	set("long","��ϲ������ٹȵ�Ѿ�ߡ�");
	set("attitude", "friendly");
	
	set("max_mp", 200);
	set("mp", 200);
	set("force_factor", 10);
	
	set("combat_exp", 5000);
	
	set_skill("unarmed", 30);
	set_skill("parry", 40);
	set_skill("dodge", 50);
	set_skill("force", 50);
	
	carry_object("mini_dress")->wear();
	carry_object("shoes")->wear();
	
};

NPC_END;
