//shennongdizi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shennongdizi);

virtual void create()
{
	set_name("神农帮弟子","shennong dizi");

	set("icon", young_man2);
	set("age", 32);
	set("gender", "男性");
	set("long", "这是一个神农帮的帮众，身穿黄衣，肩悬药囊，手持一柄药锄。");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("hammer", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("yaochu")->wield();
	carry_object("cloth")->wear();



};


NPC_END;
