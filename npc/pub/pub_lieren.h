//lieren.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_lieren);

virtual void create()
{
	set_name("����","lieren");
	
	set("icon", triggerman2);
	set("age", 32);
	set("gender", "����");
	set("long", "һλ��ǿ��׳�����������֡�");
	set("attitude", "peaceful");
	
	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 20);
	
	carry_object("wdahui")->wear();
	
	
};

NPC_END;
