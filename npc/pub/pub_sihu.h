//sihu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_sihu);

virtual void create()
{
	set_name("忽伦四虎","sihu");

	set("icon", young_man2);
	set("gender", "男性");
	set("nickname", "巨人");
	set("age", 19);
	set("long", "他是一个满洲巨人，手脚粗大，善于相扑，却生性纯朴。");
	
	set("combat_exp", 100000);
	

	set("attitude", "peaceful");
	
	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);

	carry_object("cloth")->wear();
	add_money(2);


};

NPC_END;
