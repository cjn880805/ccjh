//helpnpc001.h
//甲士
//George 2001-07-07

NPC_BEGIN(CNhelpnpc001);

void create()
{
	set_name("甲士", "jiashi");
	set("title","边境士兵");
	
	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 24);
	set("long","御卒。");
	set("attitude", "friendly");  
	set("env/wimpy", 100);
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{
	
	static char hua1[10][100]=
	{
		"想要战胜敌人，自己的防御装备是最重要的。",
			"我们的队伍号称铁甲战队。",
			"自己的生命是最重要的，我们都用最好的铁甲，绝无假冒。",
			"我们可以战胜多于自己十倍的敌人。",
			"我们的铁匠是全国最好的，打造出来的武器也是绝一无二的。",
			"我曾被授于英雄的称号，那是在一次战争之后。",
			"随时都有可能战斗的发生，我们必须小心。",
			"为了保证装备的数量，很多铸造师都很辛苦。",
			"我们用过很多种装备，很通难说哪一种是最好的。",
			"铁甲是一种很不错的装备。"
	};
	static char hua2[5][100]=
	{
		"你好，你要问什么？",
			"还有很多，如果不明白可以问我。",
			"我还知道一些其它的，你可以问我。",
			"下面的东西都不错，你是要听吧？",
			"有些装备我们很少用，不过却很清楚，你如果不明白，可以问我。"
	};
	static char hua3[7][100]=
	{
		"铁甲",
			"血棋衣",
			"铁手掌",
			"金丝甲",
			"真丝宝甲",
			"金刚罩",
			"结婚礼服",
	};
	static char hua4[7][150]=
	{
		"小辈们最流行的装备，可以减少受伤和增加点攻击力，一般都是大侠从军官身上硬抢下来的。 ",
			"一件神奇的衣服，穿上的人可以…… ",
			"上面记载了一些少林派基本的入门功夫。 还可以学习基本拳脚。",
			"高丽著名的手工业产品，用金丝加上白金丝编织成的软甲，不但外表美观华贵，还能够很大程度的防止受伤。一定程度上是身份的象征。",
			"用天山乌蚕吐的丝编织成的背心，寻常宝刀宝剑都不能伤害。不过由于乌蚕极为罕见，所以这种宝甲也就十分珍贵，不是什么地方都可以买到的。 ",
			"和伏魔刀一样都是少林的佛宝，穿上后刀剑不伤，水火不侵。 ",
			"由著名的裁缝店老板娘亲手缝制，人的一生只应该穿一次的衣服。 "
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<10;i++)
		{
			if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(5)],me);
		for(int ii=0;ii<7;ii++)
		{
			if(!random(2))
				AddMenuItem(hua3[ii], zifu(ii), me);
		}
		SendMenu(me);
		return 1;
	}
	say(hua4[shuzi(ask)],me);
	SendMenu(me);
	return 1;
}
char * zifu(int x)
{
	switch(x)
	{
	case 0:return "0";
	case 1:return "1";
	case 2:return "2";
	case 3:return "3";
	case 4:return "4";
	case 5:return "5";
	case 6:return "6";
	case 7:return "7";
	case 8:return "8";
	case 9:return "9";
	case 10:return "10";
	case 11:return "11";
	case 12:return "12";
	case 13:return "13";
	case 14:return "14";
	case 15:return "15";
	case 16:return "16";
	case 17:return "17";
	case 18:return "18";
	case 19:return "19";
	case 20:return "20";
	case 21:return "21";
	case 22:return "22";
	case 23:return "23";
	case 24:return "24";
	case 25:return "25";
	default:return "00";
	}
}
int shuzi(char * y)
{
	if(strcmp(y,"0")==0)
		return 0;
	else if(strcmp(y,"1")==0)
		return 1;
	else if(strcmp(y,"2")==0)
		return 2;
	else if(strcmp(y,"3")==0)
		return 3;
	else if(strcmp(y,"4")==0)
		return 4;
	else if(strcmp(y,"5")==0)
		return 5;
	else if(strcmp(y,"6")==0)
		return 6;
	else if(strcmp(y,"7")==0)
		return 7;
	else if(strcmp(y,"8")==0)
		return 8;
	else if(strcmp(y,"9")==0)
		return 9;
	else if(strcmp(y,"10")==0)
		return 10;
	else if(strcmp(y,"11")==0)
		return 11;
	else if(strcmp(y,"12")==0)
		return 12;
	else if(strcmp(y,"13")==0)
		return 13;
	else if(strcmp(y,"14")==0)
		return 14;
	else if(strcmp(y,"15")==0)
		return 15;
	else if(strcmp(y,"16")==0)
		return 16;
	else if(strcmp(y,"17")==0)
		return 17;
	else if(strcmp(y,"18")==0)
		return 18;
	else if(strcmp(y,"19")==0)
		return 19;
	else if(strcmp(y,"20")==0)
		return 20;
	else if(strcmp(y,"21")==0)
		return 21;
	else if(strcmp(y,"22")==0)
		return 22;
	else if(strcmp(y,"23")==0)
		return 23;
	else if(strcmp(y,"24")==0)
		return 24;
	else if(strcmp(y,"25")==0)
		return 25;
	else 
		return 100;
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

