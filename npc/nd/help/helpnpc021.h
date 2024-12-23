//helpnpc021.h
//二狗子
//George 2001-07-07

NPC_BEGIN(CNhelpnpc021);

void create()
{
	set_name("二狗子", "ergouzi");
	
	set("title","无赖");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 26);
	set("long","无赖");
	set("attitude", "friendly");  
	set("env/wimpy", 100);  
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[6][100]=
	{
		"想要报仇也不是很容易的。",
		"我有很多敌人。",
		"你如果想知道我有什么武功是不可能的。",
		"我不相信任何人。",
		"如果真想做生意，我一定会用文书。",
		"做了很多生意，哈哈，都是赚钱的买卖。"
	};
	static char hua2[2][100]=
	{
		"想学什么好东西可以问我。",
		"还有很多，你想学吗？"
	};
	static char hua3[9][100]=
	{
		"耍赖",
		"跟踪",
		"谣言",
		"诬陷",
		"报仇",
		"偷窃",
		"欺骗",
		"利用",
		"鼓动"
	};
	static char hua4[9][150]=
	{
		"如果在战斗中被人抢了经验，不要紧，你也可以抢他的。",
		"如果想锁定一个玩家的话，你只要选取“跟随某人”就可以了，那时他跑到哪里你都会跟上，建议欲复仇者使用。",
		"造一些破坏敌人名声的谣言，很有趣，而且，大部分人都很相信谣言。",
		"最绝的一招，假冒敌人，然后干尽坏事。。。。。。",
		"杀不过不要紧，有钱也可以，没钱也不要紧，认识几个江湖上的朋友也能解决。",
		"你可以学习偷窃术偷敌人的东西，如果还没学会，让朋友代偷也可以。",
		"哈哈，在江湖中，有很多人借做买卖来只收钱，不卖货的，不愧是发财的首选。可迅速赚很多钱。",
		"江湖上有很多人，你可以让他们免费做很多事的，哈哈，是不是不信？就看你怎么做了。",
		"使自己的敌人变成大家的敌人，这样就行了，很简单。势单力小者不得不采用的办法。"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<6;i++)
		{
			if(!random(2))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<9;ii++)
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

