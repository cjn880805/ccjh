// yinchang_xuedao.c  血刀老祖

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_xuedao);

virtual void create()
{
	set_name("血刀王",  "xuedao laozu");
	set("long","这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。");
	set("title","血刀门第四代掌门");
	set("gender", "男性");
	set("class", "bonze");
	set("age", 85);
        set("icon",old_man1);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_hp", 9000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	set("combat_exp", 1800000);
	set("score", 180000);
	
	set_skill("mizong_xinfa", 150);
	set_skill("literate", 80);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("blade", 400);
	set_skill("sword", 120);
	set_skill("dodge", 180);
	set_skill("longxiang", 180);
	set_skill("shenkong_xing", 180);
	set_skill("hand", 180);
	set_skill("dashou_yin", 180);
	set_skill("mingwang_jian", 120);
	set_skill("xue_dao", 200);
	
	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("hand", "dashou_yin");
	map_skill("parry", "xue_dao");
	map_skill("blade", "xue_dao");
	map_skill("sword", "mingwang_jian");
	
	create_family("雪山寺", 4, "弟子");
	set("class", "bonze");
	
	carry_object("y_jiasha")->wear();
	carry_object("gangdao")->wield();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say(" 缦胡缨是说他头上所带之缨并不精致，胡乃胡乱之意。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="jiumo-zhi")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;