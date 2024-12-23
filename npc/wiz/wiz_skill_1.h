// wiz_limian.h

//code by qinbo
//date:2001-12-31

NPC_BEGIN(CNwiz_skill_1);

virtual void create()
{
	set_name("无名",  "wu ming");
	set("gender", "男性");
	
	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
	set("icon", pub_boss);
	
	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set("no_kill", 1);
}

void init(CChar * me)
{
	CNpc::init(me);
	
	if( userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	
	if(! who) return;
	if(who->querymap("exam"))who->del("exam");
	if(who->query("liwu_weapon"))who->del("liwu_weapon");
	if(who->query("liwu_book"))who->del("liwu_book");
	if(who->query("youqin_gift"))who->del("youqin_gift");
	if(who->query("lj/清除"))who->del("lj/清除");
	if(who->query("max_atman")==1)
	{
		who->del("max_atman");
		tell_object(who, "\n$HIR你端起了无名默默递过来的一盏香茶，仰头一饮而尽，往事顿如过眼云烟般从脑海里逐一流逝。。。");
		tell_object(who, "$HIR清醒之后，你这才发现昨夜发生的一切，其实只是你的一个苦涩的、亦或是甜蜜的梦，虽然梦中有你有我。");
		tell_object(who, "$HIR“满纸荒唐言，一把辛酸泪，都云巫师痴，谁解其中味”\n");
	}
}


NPC_END;




