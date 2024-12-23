// zhangfang.c
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_zhangfang);

virtual void create()
{
	set_name("帐房先生", "zhangfang");
	set("long", "他一身邋遢，整天迷迷糊糊的睡不醒模样。");
	set("gender", "男性");
	set("attitude", "heroism");
/*	
	set("inquiry",([
		"工资"	: (: ask_for_gongzi :),
		"薪水"	: (: ask_for_gongzi :),
		"salary"  : (: ask_for_gongzi :),
		"payment" : (: ask_for_gongzi :),
		"gongzi"  : (: ask_for_gongzi :),
		]));
*/	
	set("age", 61);
	set("shen_type", 0l);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("icon",old_man1);
	set("max_hp", 500);
	set("hp", 100);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 1000);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	carry_object("cloth")->wear();
//	add_money("silver", 5);
}
/*
int ask_for_gongzi()
{
	object me, payment;
	int paytimes;
	
	me = this_player();
	if ((int)me->query("yipin/joined") )
	{
		if (!(int)me->query("yipin/lasttime") )
		{
			paytimes = 1;
			me->set("yipin/lasttime", time() );
		}
		else
		{
			paytimes = (int)(time() - me->query("yipin/lasttime"))/86400;
			me->set("yipin/lasttime", time() );
		}
		payment=new("/clone/money/gold");
		if (paytimes ==0)
		{
			tell_object(me, "帐房先生道：你的饷银已经领过了吧。\n");
		}
		else
		{
			payment->set_amount(paytimes);
			payment->move(me);
			tell_object(me, "帐房先生道：这是你的饷银，收好吧。\n");
		}
	}
	else tell_object(me,"帐房先生道：欺负我老糊涂？你根本不是一品堂的人！\n");
	return 1;
}
*/
NPC_END;