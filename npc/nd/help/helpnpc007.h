//helpnpc007.h
//蒲寿庚
//George 2001-07-07

NPC_BEGIN(CNhelpnpc007);

void create()
{
	set_name("蒲寿庚", "pushougeng");

	set("title","打不过就跑");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 50);
	set("long","一看就是一脸奸相，不象是好人。");
	set("attitude", "friendly");  
	set("env/wimpy", 100);  
	set("no_talk",1);
}  
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[4][100]=
	{
		"在江湖一定要学会保护自己。",
		"装备再好也有更厉害的，所以学会逃跑是最重要的。",
		"战斗时要机知才可以。",
		"必须保障自己不受一点点伤害。战斗才有意义。"
	};
	static char hua2[2][100]=
	{
		"你要问什么？",
		"你还有什么不明白？"
	};
	static char hua3[9][100]=
	{
		"如何增加自己的安全感？",
		"逃跑系数到底是什么？",
		"打坐系数是什么？",
		"加力系数是什么？",
		"为什么要设置这么多的系数？",
		"逃跑系数是不是越大越好？",
		"打坐系数是不是越大越好？",
		"加力系数是不是越大越好？",
		"你是谁？"
	};
	static char hua4[9][100]=
	{
		"防守是最好的进攻，如果打不过敌人，就一定要逃跑。",
		"是一个百分数，当你的HP在这个比率下的时候，系统会自动逃跑。",
		"练功时一次所需的HP",
		"在战斗时通过减少自己的MP来获得力量的一种方法，就是每次消耗的MP的比率。",
		"你如果不想设置也可以，如果牺牲了别来找我。",
		"不是，有时候你会击败一个对手，如果设置太高的逃跑系数，可能会浪费很多得经验的机会。",
		"不是，要量力而行，当用纸人的时候，有时间隔时间太短，影响练功的效果。",
		"不是，加大一次的力量和增多攻击的次数要看个人的情况而定。",
		"这个你就别多问了。。。。"
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
		for(int ii=0;ii<9;ii++)
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

