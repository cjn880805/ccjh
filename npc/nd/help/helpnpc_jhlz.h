//hu.h
//江湖郎中
//2001-01-09

VENDOR_BEGIN(CNhelpnpc_jhlz);

virtual void create()
{
	set_name("江湖郎中", "jianghulangzhong");
	set("title","妙妙手");
	set("long","江湖郎中");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("icon",young_man5); 
	set("env/wimpy", 100);      
	
	set("max_hp", 4500);
	set("hp",  1500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("score", 80000);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed",180);
	set_skill("parry", 180);

	carry_good("jiudai", 20);
	carry_good("blackcloth", 5);
	carry_good("peanut", 5);
	carry_good("yangbian", 5);
	carry_good("baozi", 10);
	carry_good("egg", 10);
	carry_good("gao", 10);
	carry_good("gao3", 10);
	carry_good("sherou", 20);
	carry_good("tanghulu", 20);
	carry_good("turou", 20);
	carry_good("bu_shoes", 20);
	carry_good("baozi2", 20);
	carry_good("backleg", 10);
	carry_good("jitui", 10);
	carry_good("mangguo", 1);
	carry_good("yadan", 4);
	carry_good("gourou", 20);
	carry_good("zongzi", 100);
	carry_good("senggun", 20);
	carry_good("chanzhang", 5);
	carry_good("qimeigun", 5);
	carry_good("ruanjian", 10);	
	carry_good("zhujian", 20);
	carry_good("jiujiebian", 20);
	carry_good("dafu", 20);
	carry_good("changjian", 20);
	carry_good("doupeng", 20);
	carry_good("shoutao", 10);
	carry_good("tiebeixin", 10);
	set("no_talk",1);
}
int do_talk(CChar * me, char * ask = NULL)
{
	char xingbie[10];
	int myage=0;
	int mylevel=0;
	myage=me->query("age");
	mylevel=me->query("level");
	static char hua1[22][10]=
	{
		"甲士",
		"太乙假人",
		"丙冰花",
		"壮丁",
		"不戊",
		"妲己",
		"蒲寿庚",
		"辛弃疾",
		"壬人",
		"天癸哥",
		"小孙子",
		"小丑",
		"唐寅",
		"兔兔女",
		"龙娇娇",
		"蛇公主",
		"白龙马",
		"未卜知",
		"申沉",
		"彭酉",
		"二狗子",
		"猪不戒"
	};
	static char hua2[22][30]=
	{
		"求之不得啊！",
		"快说，烦死了。。",
		"多谢，你讲吧！",
		"非常感谢！",
		"说也无妨。",
		"说吧，说不定我也认识呢！",
		"朋友多了好啊！",
		"说呀，还等什么？",
		"我也很愿意交朋友啊！",
		"朋友？有趣，请讲。",
		"到底都是些什么人啊？",
		"你朋友是不是很多啊？",
		"还烦请介绍一二了。",
		"呵呵！我倒要听一听。",
		"你们熟吗？你还是先讲吧。",
		"好的，我正想认识一下呢。",
		"愿闻其详。",
		"我只是路过，听听也好。",
		"我到这里就是为了交朋友。",
		"说吧，我会记住的。",
		"我正愁没人帮忙呢！",
		"这还用说？"
	};

	static char hua3[22][60]=
	{
		"让我想想。。。",
		"现在只记得以下这么多了。",
		"这些人有些已经好久没见面了。",
		"这里面人大部分都找我治过病。",
		"这些人可能有些你也碰到过。",
		"我的朋友三教九流，很可能有些人已经隐居了。",
		"朋友太多了，我说哪一个呢？好了，下面这几个你听一下。",
		"我现在还有一些新朋友，不过不记得名字了，想起谁就说谁吧。",
		"如果你见到他们，就说是我的朋友。",
		"你也要认识些朋友啊，这些人有很多都是我的老朋友了。",
		"现在给你讲的朋友不知道改行了没有？",
		"可能是年纪大了，只能记得以下几个了。",
		"其实做生意也能认识好多朋友，可能下面的朋友就做生意去了。",
		"帮助人治病可以认识很多朋友，所以我们这一行认识的朋友很多。",
		"我这些朋友都很有威望的，能遇到他们是你的幸运。",
		"有些朋友可能随着时间的增长，对你态度会不一样的。",
		"他们有些人很怪，可能你遇到他们才会知道。",
		"我经常向人介绍朋友的，你不用谢我。",
		"我也有一些朋友是大侠，但他们不让我透露他们的真实姓名。",
		"我也有一些朋友是魔头，我不敢说出他们的真实姓名。",
		"你问完之后就赶快离开这里，今天找我的人太多了。",
		"昨天睡的比较好，今天可能能多想出几个。"
	};

	if(!strlen(ask))
	{
		char msg1[50];
		strcpy(xingbie,me->querystr("gender"));
		if(strcmp(xingbie,"女性")==0)
			strcpy(msg1,"小姐，你受伤了，需要帮忙吗？");
		else if(strcmp(xingbie,"男性")==0)
			strcpy(msg1,"小兄弟,你受伤了，需要帮忙吗？");
		else
			strcpy(msg1,"小公公,你受伤了，需要帮忙吗？");
		if(!random(5))
			say("你听人说过“神医张”吗？那就是说我呢，遇到我是你的福气啊！！",me);
		if(!random(5))
			say("我只给小辈疗伤！",me);
		if(!random(5))
			say("人在江湖，朋友要多，如果需要帮忙请尽管开口，",me);
		if(!random(5))
			say("我有一个怪习惯，给小辈只治病，不收钱。",me);
		if(!random(5))
			say("我最讨厌无情无义之徒。希望你不是。",me);
		if(!random(5))
			say("有很多人都是我救的，不信你可以到处打听打听。",me);
		if(!random(5))
			say("如果你有朋友受伤，就让他们来找我。",me);
		if(!random(5))
			say("野外有很多毒蛇，走路也要小心啊！",me);
		if(!random(5))
			say("有些地方的侍卫会攻击来访者，有很多朋友就受到了他们的伤害。",me);
		if(!random(5))
			say("我卖的药不贵，公平合理，你也可以试一试。",me);
		if(!random(5))
			say("今天有个受伤者是被巡捕杀伤的，但我还是救了他。",me);
		if(!random(5))
			say("我还有很多同门在开药铺，你一定会遇到他们的。",me);
		if(!random(5))
			say("因为没有固定居所，我只好到处流浪为生。",me);
		if(!random(5))
			say("身上不要带太多的财物，很多盗贼会见财起色。",me);
		if(!random(5))
			say("我把钱都存钱庄里了，现在只有这些药品了。",me);
		if(!random(5))
			say("我曾经到野外采过些草药，差点被毒蛇咬伤。",me);
		if(!random(5))
			say("帮的人太多了，真记不起你是谁了。",me);
		if(!random(5))
			say("今天找我的人很多，好累。",me);
		if(me->query("max_hp")!=me->query("eff_hp")&&myage==14)
	   {
			say(msg1,me);
			AddMenuItem("好的，多谢了！", "a", me);
			AddMenuItem("不用。", "b", me);
			SendMenu(me);
			return 1;

	   }
	   else
	   {
		   if(me->query_temp("talk/times")>2)
			   return 0;
			say("用不用帮你介绍几个朋友啊？",me);
			AddMenuItem(hua2[random(22)], "00", me);
			SendMenu(me);
			return 1;
	   }
//       AddMenuItem("", "2", me);
	}
	if(strcmp(ask,"a")==0)
	{
		message_vision("江湖郎中喂$N服下一颗药丸,然后盘膝坐下，双掌贴着$N的背心。", me);
		me->set("eff_hp",  me->query("max_hp"));
		message_vision("大约过了不到一盅茶的时份，江湖郎中慢慢地站了起来。",me);
		message_vision("江湖郎中对$N说道：你的伤势已经全好了,可以走啦。", me);
		say("好了，再睡一觉吧！",me);
	}
	else if(strcmp(ask,"b")==0)
	{
		message_vision("江湖郎中对$N说道：你是不是小看我的医术啊？给我坐下。", me);
		message_vision("江湖郎中喂$N服下一颗药丸,然后盘膝坐下，双掌贴着$N的背心。", me);
		me->set("eff_hp",  me->query("max_hp"));
		message_vision("大约过了不到一盅茶的时份，江湖郎中慢慢地站了起来。",me);
		message_vision("江湖郎中对$N说道：你的伤势已经全好了,可以走啦。", me);
		say("好了，记住下次受伤要治疗才对啊！",me);
	}
	else if(strcmp(ask,"00")==0)
	{
		say(hua3[random(22)],me);
		me->set_temp("talk/times",me->query_temp("talk/times")+1);
		if(!random(4))
			AddMenuItem(hua1[0], "0", me);
		if(!random(4))
			AddMenuItem(hua1[1], "1", me);
		if(!random(4))
			AddMenuItem(hua1[2], "2", me);
		if(!random(4))
			AddMenuItem(hua1[3], "3", me);
		if(!random(4))
			AddMenuItem(hua1[4], "4", me);
		if(!random(4))
			AddMenuItem(hua1[5], "5", me);
		if(!random(4))
			AddMenuItem(hua1[6], "6", me);
		if(!random(4))
			AddMenuItem(hua1[7], "7", me);
		if(!random(4))
			AddMenuItem(hua1[8], "8", me);
		if(!random(4))
			AddMenuItem(hua1[9], "9", me);
		if(!random(4))
			AddMenuItem(hua1[10], "10", me);
		AddMenuItem("红龄", "hong", me);
		if(!random(4))
			AddMenuItem(hua1[11], "11", me);
		if(!random(4))
			AddMenuItem(hua1[12], "12", me);
		if(!random(4))
			AddMenuItem(hua1[13], "13", me);
		if(!random(4))
			AddMenuItem(hua1[14], "14", me);
		if(!random(4))
			AddMenuItem(hua1[15], "15", me);
		if(!random(4))
			AddMenuItem(hua1[16], "16", me);
		if(!random(4))
			AddMenuItem(hua1[17], "17", me);
		if(!random(4))
			AddMenuItem(hua1[18], "18", me);
		if(!random(4))
			AddMenuItem(hua1[19], "19", me);
		if(!random(4))
			AddMenuItem(hua1[20], "20", me);
		if(!random(4))
			AddMenuItem(hua1[21], "21", me);

	}
	else if(strcmp(ask,"hong")==0)
	{
		say("你可能已经见过她了，如果还有什么问题，你还可以继续找她。她一定会帮忙的。",me);
	}
	else if(strcmp(ask,"0")==0)
	{
		say("据说是最有威力的御林军，他们装备严密，素来很少与江湖接触。我认识几个，不过都没记住姓名。",me);
	}
	else if(strcmp(ask,"1")==0)
	{
		say("他原是武当门下，道士出身。研究机器机关，通晓奇门遁甲，据说木偶人和纸人就是他发明的",me);
		say("好久没见过他了，不过据江湖传闻，最近他又发明了一种万能机器人，不过好象还未在江湖上出现。",me);
		say("小兄弟如果有缘得到的话，还请让大家也开开眼界。",me);
	}
	else if(strcmp(ask,"2")==0)
	{
		say("她是我所见过的最可爱的江湖女侠了，长期与花草为伍，也了解一些暗器的原理和使用方法",me);
	}
	else if(strcmp(ask,"3")==0)
	{
		say("由于长年的江湖纷争，各大门派势均力敌，又互相撕杀，所以大家都要不断地招募新人，我见过很多壮丁，他们大都很穷困。",me);
		say("我见过的壮丁现在大部分已参加了各门各派了，也有为皇上卖命的。你看到外面巡城的宋兵中，说不定还认识我呢。",me);
	}
	else if(strcmp(ask,"4")==0)
	{
		say("江湖现在有很多门派都正在通辑他，可能是他泄露的秘密太多了吧？你也要小心一点，“江湖通辑令”可是吃不消的。",me);
	}
	else if(strcmp(ask,"5")==0)
	{
		say("人皮面具就是她做的，她也懂一些岐黄之术，其实她是丑八怪，不知怎么就整成现在的样子了。你要小心，说不定哪天就用你的名字去招摇撞骗了。",me);
	}
	else if(strcmp(ask,"6")==0)
	{
		say("他原来也是我的朋友，不过有人造谣说他最近投靠了敌国，也不知道是真是假。",me);
	}
	else if(strcmp(ask,"7")==0)
	{
		say("如果你能得到他的一点指导，对你的才智一定会大有帮助。",me);
	}
	else if(strcmp(ask,"8")==0)
	{
		say("小心他的讲话，我多次受过他的骗，都是后来才知道的。",me);
	}
	else if(strcmp(ask,"9")==0)
	{
		say("他家中收藏有很多古怪的兵器，我每次见到他都会见他使用不同的武器，不过，好象他又从来不与人切磋，真的很怪。",me);
	}
	else if(strcmp(ask,"10")==0)
	{
		say("噢！请你别误会，他不是我的孙子。只是江湖上对一个谋士的尊称，你如果见到他的话，可能会帮你很多忙。",me);
	}
	else if(strcmp(ask,"11")==0)
	{
		say("有小丑演出的戏我是每场必看的，非常精彩！有时候也会看到他们在街头卖艺，观众很多。",me);
	}
	else if(strcmp(ask,"12")==0)
	{
		say("你难道没听说过他吗？四大才子之首啊？你随便问一个人都知道的啊！",me);
	}
	else if(strcmp(ask,"13")==0)
	{
		say("这个人我没见过，你可以问一下其他的人。不过好象天天找她的人很多。",me);
	}
	else if(strcmp(ask,"14")==0)
	{
		say("说起来真是惭愧，那次帮她疗伤，被她侮辱够了，我再也不想见她了。下次别在我面前提起她。",me);
	}
	else if(strcmp(ask,"15")==0)
	{
		say("当今王爷的七公主，如果不是王爷对我有恩，我才不会给她治呢，算了，你遇到她就知道了。",me);
	}
	else if(strcmp(ask,"16")==0)
	{
		say("这不知道是不是他的真名，但大家都这么叫他，每天就是说要到西天取经，莫明其妙！",me);
	}
	else if(strcmp(ask,"17")==0)
	{
		say("是阴阳先生，人称“前知五百年，后推三百年”，三十年前他就说我是郎中，很玄，不过他很少泄露天机，一定要是有缘人才行。",me);
	}
	else if(strcmp(ask,"18")==0)
	{
		say("我不是很了解他，他好象经常有什么事情。",me);
	}
	else if(strcmp(ask,"19")==0)
	{
		say("在江湖上一个人行走很不容易，没几个朋友是不行的，关于一些简单的基本问题，你可以向他请教，他定会知无不言，言无不尽。",me);
	}
	else if(strcmp(ask,"20")==0)
	{
		say("是一个十足的无赖，离他远一些还是好。很难缠。",me);
	}
	else if(strcmp(ask,"21")==0)
	{
		say("又是一个酒肉和尚，你见到他就知道了。",me);
	}
	else
	{
		return 0;
	}
		
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
VENDOR_END;