//weishi2.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_weishi2);

virtual void create()
{
	set_name("锦衣卫士","weishi");

	set("icon", general);
	set("age", 32);
	set("gender", "男性");
	set("long", "这是位锦衣卫士，身着锦衣，手执钢刀，双目精光炯炯，警惕地巡视着四周的情形。");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 24);
	set("dex", 16);
	set("combat_exp", 30000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 100);
	set_skill("parry", 40);
	set_skill("blade", 100);
	set_skill("force", 40);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("gangdao")->wield();
	carry_object("jjunfu")->wear();

};


NPC_END;
