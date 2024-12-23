// wang.c
//sound 2001-07-18

NPC_BEGIN(CNfuzhou_wang);

virtual void create()
{
	set_name("王夫人", "wang furen");
	set("gender", "女性");
	set("title", "金刀");
	set("long", "她是洛阳金刀王老爷子的独生爱女，福威镖局总镖头夫人。");
	set("age", 39);
	set("icon",young_woman12);
	
	set("combat_exp", 25000);
	set("shen_type", 1);
	
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("yanxing_dao", 50);
	map_skill("parry", "yanxing_dao");
	map_skill("blade", "yanxing_dao");
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}
NPC_END;