//pub_whitelady.c 
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_whitelady);


virtual void create()
{
	set_name("白衣少女","white lady" );

	set("icon", young_woman4);
	set("gender", "女性" );
	set("age", 18);
	set("long", "一个聪明伶俐的白衣少女。");
	set("shen_type", -1);
	set("combat_exp", 1000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_hp", 300);
	set("mp", 100);
	set("max_mp", 100);
	set("score", 800);
	
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
	create_family("白驼山派", 10, "弟子");
        set_inquiry("白少庄主","每个人都说他是坏人，他自己也说自己是坏人，但是我还是觉得他人很好。");
	carry_object("baipao")->wear();
}

/*
virtual char * greeting(CChar * ob)
{
	char msg[255];
	return snprintf(msg,255,"白衣少女招招手说道：这位%s，过来和我们一起玩捉迷藏吧。",query_respect(ob) );
}
*/

NPC_END;