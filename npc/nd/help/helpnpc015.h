//helpnpc015.h
//龙娇娇
//George 2001-07-07

NPC_BEGIN(CNhelpnpc015);

void create()
{
	set_name("龙娇娇", "longjiaojiao");
	set("title","天之娇女");

	set("icon", girl1);
	set("gender", "女性" );
	set("age", 18);
	set("long","龙娇娇");
	set("attitude", "friendly");  
	set("env/wimpy", 100);  
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"谁说女子就不能做皇帝了？",
		"江湖有很多女侠声望和武功都在男侠之上。",
		"女子有很多武功强过男子的，只是很多人不知道。",
		"我要比武招亲。",
		"我发现一个秘密，在少林寺中有很多武功的创始人是女子。"
	};
	say(hua1[random(5)],me);
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

