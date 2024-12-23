// youngwoman.c
//code by sound
//12-16

NPC_BEGIN(CNemei_youngwoman);

virtual void create()
{
 	set("icon",young_woman9);
	set_name("年轻少妇", "nianqing shaofu");
	set("gender", "女性" );
	set("age", 16);
	set("long", "这是一个长途疲惫的年轻少妇。");
	set_temp("apply/defense", 5);
	set("combat_exp", 1000);
	set("shen", 500);
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
}

NPC_END;