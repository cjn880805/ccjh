//youngwoman.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_youngwoman);

virtual void create()
{
	set_name("�����ٸ�","youngwoman");
	
	set("icon", young_woman11);
	set("gender", "Ů��" );
	set("age", 16);
	set("long","����һ����;ƣ���������ٸ���");
	set_temp("apply/defense", 5);
	set("combat_exp", 1000);
	set("repute", 500);
	set("shen_type", 1);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_skill("sword", 10);
	set_skill("force", 10);
	set_temp("apply/attack", 10000);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	
	set("attitude", "friendly");
	carry_object("cloth")->wear();

};



NPC_END;
