//helpnpc018.h
//未卜知
//George 2001-07-07

NPC_BEGIN(CNhelpnpc018);

void create()
{
	set_name("未卜知", "weibuzhi");
	
	set("title","阴阳先生");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 80);
	set("long","眼睛眯缝着，象在偷偷地看着什么。。。");
	set("attitude", "friendly");  
	set("env/wimpy", 100);    
	set("no_talk",1);
} 

int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"根据我对天相的观察，发现在西北方将有一个重大人物出现。",
		"黄河一带在三天之内必有水灾。",
		"门派的纷争马上就要开始了。",
		"我看到在北方，有一片红光在闪烁。。。",
		"有很多事情要发生，到时候大家就知道了。"
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

