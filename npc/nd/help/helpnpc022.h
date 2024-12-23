//helpnpc022.h
//猪不戒
//George 2001-07-07

NPC_BEGIN(CNhelpnpc022);

void create()
{
	set_name("猪不戒", "zhubujie");
	
	set("title","酒肉和尚");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 32);
	set("long","街头人物。");
	set("attitude", "friendly");  
	set("env/wimpy", 100);  
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{
	if(random(2))
		return 0;
	static char hua1[20][100]=
	{
		"去哪里一定要带上食物才可以。",
		"我最爱吃的食物是鸡腿，你要不要也来一个？",
		"酒，说什么都不能戒。",
		"谁说我没有家，只是四海为家嘛！！",
		"不要逼我出手，我一般不轻易显露功夫的。",
		"今天又捡了很多金子，又可以喝酒了，感觉不错。",
		"如果有破烂玩意不想要的话，可以给我，很有用，可以用来当酒喝。",
		"我从来不偷东西，最多是乞讨。",
		"别把我当丐帮的人，我与他们不同。",
		"今天天气正好，可以多睡一会儿。",

		"为什么不与我做朋友？",
		"这里就是我的家，什么地方我也不去。",
		"天亮的太快了，还没睡够。",
		"如果遇到女儿红，别忘了帮我带一瓶。",
		"昨天有人送我一千金子，你是不是也要送啊？",
		"有位大侠要收我为徒，可是我并没有同意。",
		"为什么会有丐帮？",
		"我又梦到了金山，说不定真有金山，你说是吗？",
		"醉了不要紧，多睡一会就可以了。",
		"最近要举行武林大会，不知你听说了没有？",
	};
	say(hua1[random(20)],me);
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

