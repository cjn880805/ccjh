//helpnpc009.h
//壬人
//George 2001-07-07

NPC_BEGIN(CNhelpnpc009);

void create()
{
	set_name("壬人", "renren");

	set("title","天马行空");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 50);
	set("long","抬头望着天空，一脸迷惘的表情。");
	set("attitude", "friendly");   
	set("env/wimpy", 100);    
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{
	if(random(2))
		return 0;

	static char hua1[4][100]=
	{
		"在天山附近可以找到倚天剑。",
		"有一个山洞，据说到那里的武功秘籍特别多，都是刻在石壁上的。",
		"苏州有很多钱庄，老板定期会发钱给存钱在那里的人。",
		"北京城郊外有一怪兽，如果能杀死它，王爷会奖赏他很多金子，但现在还是没有人捉住它。"
	};
	say(hua1[random(4)],me);
	SendMenu(me);
	return 1;
}

virtual int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s我怎么是大侠的对手呢？",query_respect(me) ));
	return 0;
}
/*
virtual void die()
{
	revive(1);
//	message_vision("$N望空中深深的吸了口气。", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}
*/
NPC_END;

