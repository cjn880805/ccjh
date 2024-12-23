//qiu_wanjia.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_qiu_wanjia);

virtual void create()
{	
	set_name("裘百家", "qiu baijia");
	set("title", "丐帮二袋弟子");
	set("gender", "男性");
	set("age", 16);
	set("long","这是位地痞似的丐帮二袋弟子，看来是个吃得看的小地痞。");
	set("icon",begger);
	
	
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 19);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_hp", 390);

	set("beggarlvl", 2);

	set("mp", 170);
	set("max_mp", 170);
	set("mp_factor", 10);
	set("combat_exp", 8000);

	set_skill("force", 35);
	set_skill("huntian_qigong", 35);
	set_skill("unarmed", 35);
	set_skill("xianglong_zhang", 35);
	set_skill("dodge", 35);
	set_skill("xiaoyaoyou", 35);
	set_skill("parry", 35);
	set_skill("begging", 35);
	//        set_skill("checking", 35);
	set_skill("xunshou_shu", 35);

	carry_object("dawancha", 1);

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	create_family("丐帮", 20, "弟子");
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "男性"))
	{
		say("我们丐帮功夫走的是刚猛的路子，mm你学了会有失仪态的。");
		return;
	}
	else
		accept_student(me);
}

NPCGAIBANG_END;
