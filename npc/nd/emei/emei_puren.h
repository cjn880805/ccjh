// puren.c 仆人
//code by sound
//12-16

NPC_BEGIN(CNemei_puren);

virtual void create()
{
 	set("icon",waiter);
	set_name("仆人", "pu ren");
	set("age", 18);
	set("gender", "男性");
	set("long", "这是一个长途陪伴侍侯少妇的仆人。");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 80);
	set_skill("force", 60);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 80);
	
	carry_object("cloth")->wear();
}

NPC_END;