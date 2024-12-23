//helpnpc020.h
//彭酉
//George 2001-07-07

NPC_BEGIN(CNhelpnpc020);

void create()
{
	set_name("彭酉", "pengyou");
	
	set("title","小不懂");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 19);
	set("long","一脸笑容。");
	set("attitude", "friendly");    
	set("env/wimpy", 100); 
	set("no_talk",1);
}  
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[3][100]=
	{
		"在对战时，最重要的就是要知道自己的力量。",
		"只有全面提高自己各方面的能力，才有可能在战斗中取胜。",
		"在战斗中，级别也是很重要的因素。"
	};
	static char hua2[2][100]=
	{
		"有些属性不明白可以问我。",
		"我可以告诉你一些属性有什么作用。"
	};
	static char hua3[9][100]=
	{
		"力量",
		"体质",
		"智能",
		"敏捷",
		"负重",
		"攻击",
		"防御",
		"等级",
		"技能"
	};
	static char hua4[9][200]=
	{
		"就是你天生的力量，能左右你的攻击力的大小，也决定你身上能够背多少东西。",
		"就是你的身体健康程度，体质好的人比较经得起打，受了伤恢复得也快。",
		"就是聪明了，聪明的人学武功特别快，也比较受门派的欢迎。",
		"速度快的人不容易被打中，容易打中别人，打架的时候比人家悠闲，逃跑的时候也跑得快。",
		"每个人能背的东西都有一个上限，越强壮的人就能背越多东西。避免了看见好东西却背不了。",
		"当然就是指你的攻击力了，攻击力强，杀伤力就越强……攻击力是由很多因素组成的，主要由强壮、等级、武功等级、所装备武器等等…… ",
		"当然是防御力了，由敏捷，等级、轻功等级，所装备防具等等决定。",
		"等级是很重要的东西，等级高了HP也会增多，打架也特别厉害，要学高深的武功等级也不能太低。所以建议有了经验就尽快用来升级。",
		"分为基本和高级两种，有基本两字就就是基本技能，没有的就是高级技能。"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<3;i++)
		{
			//if(!random(3))
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

