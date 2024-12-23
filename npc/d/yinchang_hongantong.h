// yinchang_hongantong.c 洪安通

//code by Fisho
//date:2000-12-23
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_hongantong);

virtual void create()
{
	set_name("洪教主",  "hong antong");
	set("title",  "神龙教教主" );
	set("nickname",  "永享仙福" );
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主。");
	set("gender", "男性");
	set("age", 50);
        set("icon",old_man1);

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
	say(" 夫人所说甚是有理，但这句似更含深意。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="su-quan")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	say(" 横剑似指剑行之势。。。");
	return "";
}
*/

NPC_END;