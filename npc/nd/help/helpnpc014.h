//helpnpc014.h
//兔兔女
//George 2001-07-07

NPC_BEGIN(CNhelpnpc014);

void create()
{
	set_name("兔兔女", "tutunv");

	set("title","乖乖");

	set("icon", girl1);
	set("gender", "女性" );
	set("age", 18);
	set("long","满脸笑容，看上去就象是遇到了喜事。");
	set("attitude", "friendly");  
	set("env/wimpy", 100);    
	set("no_talk",1);
} 
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[13][100]=
	{
		"如果被PK了不要生气，要努力练功。",
		"如果有自己喜欢的人，可以到红娘庄办理结婚手续，不过要有很多钱才行。",
		"在江湖中朋友多了不一定好。",
		"我现在只有几个好朋友，还有一个朋友已经不在了。",
		"有很多大侠会免费赠送名剑。",
		"如果你要结婚，不要忘了给我礼物！",
		"我在这里守候的原因完全是因为自己还没有找到心爱的人。",
		"我养了很多小动物，你如果喜欢，我可以带你去看一下。",
		"江湖上还要发生很多的事，每天赚钱和练功还是必要的。",
		"有些朋友因为杀人太多，最终成为人们眼中的“魔头”。",

		"抑恶就是扬善，所以杀人并不是什么坏事，只是看你要杀什么人了，声望和被杀的人有很大的关系。",
		"如果认为你自己的功夫不错的话，可以向掌门提出挑战，那样，你就会成为本派的掌门了。",
		"做了掌门之后，自己可以收徒弟。徒弟的好坏对自己的名声置关重要。"
	};
	say(hua1[random(13)],me);
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

