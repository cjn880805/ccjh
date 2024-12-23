//helpnpc017.h
//白龙马
//George 2001-07-07

NPC_BEGIN(CNhelpnpc017);

void create()
{
	set_name("白龙马", "bailongma");
	
	set("title","使者");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 25);
	set("long","脸色很白，一看就知道是天生如此");
	set("attitude", "friendly");    
	set("env/wimpy", 100);  
	set("no_talk",1);
}  
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"除了战斗，有很多任务可以做。",
		"有些任务需要一定的条件。",
		"做任务会有一定的难度。",
		"唐僧是我的师傅。",
		"如果做任务时有困难，可以找朋友帮忙。"
	};
	static char hua2[2][100]=
	{
		"我知道一些任务可以告诉你。",
		"如果有机会，可以试一下下面的任务。"
	};
	static char hua3[6][100]=
	{
		"泉州找东西和杀人的任务。 ",
		"泉州收购美男子的任务。 ",
		"万劫谷任务 ",
		"护送唐僧西去任务 ",
		"MM的任务 ",
		"拣垃圾的任务 "
	};
	static char hua4[6][100]=
	{
		"找到水栀子你就知道了。在泉州。",
		"找南嗔，他要容貌20以上的男性NPC。不知他又在搞什么鬼。 ",
		"你要先到万劫谷石屋，10级以上可做。茫茫人海里找人杀人的任务,很难!奖励很高。",
		"黄河一带，要求两人（25级到30级可做 <集体任务,刺激>）",
		"阴阳合和散，红烧鸡翅，弹珠，情书，发现其中一样,送给特定NPC,有丰厚奖励。这些东西好沉,力量要够大才行",
		"看见地上有小破木头之类的垃圾,可以卖给佛山收垃圾的人.有经验奖励. 这可是白捡的任务，一定要好好珍惜。"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<5;i++)
		{
			if(!random(2))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<6;ii++)
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

