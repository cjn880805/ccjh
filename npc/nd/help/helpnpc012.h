//helpnpc012.h
//小丑
//George 2001-07-07

NPC_BEGIN(CNhelpnpc012);

void create()
{
	set_name("小丑", "xiaochou");
	set("title","玩的开心");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 25);
	set("long","测试人物");
	set("attitude", "friendly");  
	set("env/wimpy", 100);   
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[4][100]=
	{
		"在游戏中要注意很多事项，不知道不行。",
		"要遵守游戏纪律。",
		"在游戏中是完全自由的，但不能牵扯到游戏外。",
		"在游戏中PK都是可以的，如果PK太多会被巡捕追杀。"
	};
	static char hua2[2][100]=
	{
		"还要问什么？",
		"有什么不明白就说。",
	};
	static char hua3[10][100]=
	{
		"能用我自己的程序吗？",
		"我帮朋友解谜可以吧",
		"我想同时控制几个程序。",
		"我想屠杀。",
		"我要雇用杀手。",
		"下毒是我的长项。",
		"暗算玩家不会被踢吧？",
		"行骗？",
		"哈，我发现了bug.",
		"我要每天PK很多玩家。"
	};
	static char hua4[10][100]=
	{
		"在游戏中不准使用非官方的自动∕半自动程序，否则后果自负。",
		"泄漏游戏秘密关键的解法是绝对禁止的。",
		"不允许同时用三个或三个以上的角色进入游戏。 ",
		"可以。",
		"雇多少个都没问题。",
		"那你就发挥特长吧。",
		"在游戏中暗算可以，但不许盗用ID，严重者作封档处理，永久不能使用。",
		"骗谁都可以，你不怕追杀就可以。",
		"你最好报告，否则利用其损害其它玩家的利益做封档处理。",
		"只要不是恶意PK新手，就是同一天PK同一人三次以上。其它正当的PK都是允许的。"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<4;i++)
		{
			if(!random(2))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<10;ii++)
		{
			if(!random(3))
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

