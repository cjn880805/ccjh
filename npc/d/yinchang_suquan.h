// yinchang_suquan.c 苏荃

//code by Fisho
//date:2000-12-23
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_suquan);

virtual void create()
{
	set_name("苏情",  "su quan");
	set("title",  "神龙教教主夫人" );
	set("long", "一个千娇百媚、明艳不可方物的少妇。");
	set("gender", "女性");
	set("age", 25);
        set("icon",young_woman7);

	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1500000);
	set("score", 400000);
	
	set_skill("force", 200);
	set_skill("hunyuan_yiqi", 150);
	set_skill("shenlong_xinfa", 200);
	set_skill("dodge", 180);
	set_skill("yixingbu", 160);
	set_skill("unarmed", 200);
	set_skill("shenlong_bashi", 200);
	set_skill("parry", 150);
	set_skill("staff", 200);
	set_skill("shedao_qigong", 180);
	set_skill("literate", 100);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("parry", "shedao_qigong");
	map_skill("staff", "shedao_qigong");
	setup();
	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
	add_money( 5000);
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say(" 横剑纯为守势，膝前膝前更不可解。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="hong-antong")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;