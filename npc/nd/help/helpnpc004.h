//helpnpc004.h
//壮丁
//George 2001-07-07

NPC_BEGIN(CNhelpnpc004);

void create()
{
	set_name("壮丁", "zhuangding");
	set("title","实力派");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 20);
	set("long","一个非常精壮的汗子。");
	set("attitude", "friendly");    
	set("env/wimpy", 100);   
	set("no_talk",1);
}  
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[6][100]=
	{
		"有很多人喜欢PK",
		"我也比较喜欢PK",
		"自己被PK的感受是很不好的。。。。。。",
		"我们邻居有很多人为了安全，都投入了各大门派了。",
		"今天你PK了吗",
		"我还有很重要的事，不能在这里多呆。"
	};
	static char hua2[2][100]=
	{
		"你如果不懂什么，可以问我。",
		"你还有什么问题吗？"
	};
	static char hua3[10][100]=
	{
		"什么是PK?",
		"什么是NK?",
		"你被砍过吗？",
		"我受伤了怎么办啊？",
		"你杀过人吗？",
		"我被人砍过无数次，怎么办啊？",
		"你愿意帮我报仇吗？",
		"为什么有些人见都没见过就上来砍我啊？",
		"我要报仇。",
		"我打不过他们哪，怎么办？"
	};
	static char hua4[10][100]=
	{
		"玩家打玩家就是PK了，在江湖中PK与被PK都是很平常的，不要觉得奇怪。",
		"你是不是想NK？我奉陪。",
		"当然被砍过了，不过我也砍过很多人，我谁都不怕。",
		"受伤了当然是找人治疗了，在客栈里有很多大侠为人疗伤的。",
		"记得有一次。。。。。。",
		"这个问题你别问我，我不会帮你的，自己想办法吧。",
		"为什么要帮你？",
		"可能是你长的太漂亮了吧？",
		"。。。。。。。。",
		"废话，努力练功啊，你找朋友帮你也可以，不过可别找我。"
	};
	if(!strlen(ask))
	{
		
		if(random(2))
			return 0;
		for(int i=0;i<6;i++)
		{
			if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<10;ii++)
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

