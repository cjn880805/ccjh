// yinchang_jiumozhi.c 鸠摩智

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_jiumozhi);

virtual void create()
{
	set_name("鸠摩香", "jiumo zhi");
	set("nickname",  "大轮明王" );
	set("long","他就是雪山寺的掌门，人称大轮明王的鸠摩香。他对佛法有精深的研究。身穿一件大红袈裟，头带僧帽。");
	set("title","雪山寺掌门");
	set("gender", "男性");
	set("age", 60);
        set("icon",old_man1);

	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 100);
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("force", 200);
	set_skill("xiaowuxiang", 200);
	set_skill("dodge", 200);
	set_skill("shenkong_xing", 150);
	set_skill("unarmed", 200);
	set_skill("yujiamu_quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("mingwang_jian", 200);
	set_skill("mizong_xinfa", 200);
	set_skill("literate", 100);
	set_skill("staff", 100);
	set_skill("xiangmo_chu", 100 );
	set_skill("strike", 200 );
	set_skill("huoyan_dao", 200);
	
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "mingwang_jian");
	map_skill("sword", "mingwang_jian");
	map_skill("staff", "xiangmo_chu");
	map_skill("strike","huoyan_dao");
	
	prepare_skill("strike","huoyan_dao");
	
	create_family("雪山寺", 1, "掌门");
	set("class", "bonze");
	
	carry_object("r_jiasha")->wear();
	carry_object("sengmao")->wear();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;
	int i;
	
	obj = all_inventory(me->environment());
	say(" 赵客缦胡缨，胡缨的样子应该是这样的，这是否暗指行掌之势？");
	command("consider");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="xuedao-laozu")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;