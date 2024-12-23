// wiz_limian.h

//code by qinbo
//date:2001-12-31

NPC_BEGIN(CNwiz_skill_1);

virtual void create()
{
	set_name("����",  "wu ming");
	set("gender", "����");
	
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
	if(who->query("lj/���"))who->del("lj/���");
	if(who->query("max_atman")==1)
	{
		who->del("max_atman");
		tell_object(who, "\n$HIR�����������ĬĬ�ݹ�����һյ��裬��ͷһ�����������¶���������̰���Ժ�����һ���š�����");
		tell_object(who, "$HIR����֮������ŷ�����ҹ������һ�У���ʵֻ�����һ����ɬ�ġ���������۵��Σ���Ȼ�����������ҡ�");
		tell_object(who, "$HIR����ֽ�����ԣ�һ�������ᣬ������ʦ�գ�˭������ζ��\n");
	}
}


NPC_END;




