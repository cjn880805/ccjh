//yinchang_ouyangfeng.c

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_ouyangfeng);

virtual void create()
{
	set_name("白老庄主",  "ouyang feng");
	set("long", "他是白驼山老庄主。由于被蓉儿欺骗，突然走火入魔，已变得精神错乱，整日披头散发。");
	set("title", "白驼山庄主");
	set("gender", "男性");
	set("age", 53);
        set("icon",old_man1);

	set("nickname",  "西毒" );
	set("shen_type",-1);
	set("repute", -150000);
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);
	
	set("hp", 2500);
	set("max_hp", 7500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	
	set_skill("force", 200);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",170);
	set_skill("staff", 170);
	set_skill("hamagong", 200);
	set_skill("chanchu_bufa", 170);
	set_skill("shexing_diaoshou", 170);
	set_skill("lingshe_zhangfa", 170);
	
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");
	
	create_family("白驼山派",1, "开山祖师");

	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
	add_money(5000);
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say(" 十步一人，百步十人，人力有限，如何杀呢。");
	command("consider");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="ding-chunqiu")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;