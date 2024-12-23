//shami.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shami);

virtual void create()
{
	set_name("Сɳ��","shami");
	
	set("icon", young_monk);
	set("long","���Ǳ���Сɳ�֡�");
	set("gender", "����");
	set("age", 12);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
	
	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_hp", 450);
	set("mp", 150);
	set("max_mp", 150);
	
	set("combat_exp", 2000);
	set("score", 1000);
	
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	
	carry_object("test")->wear();
	
	
};


NPC_END;
