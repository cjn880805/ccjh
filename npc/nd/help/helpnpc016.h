//helpnpc016.h
//蛇公主
//George 2001-07-07

NPC_BEGIN(CNhelpnpc016);

void create()
{
	set_name("蛇公主", "shegongzhu");
	set("title","刁钻小姐");

	set("icon", girl1);
	set("gender", "女性" );
	set("age", 20);
	set("long","头戴一朵黄花，十分可爱。");
	set("attitude", "friendly");   
	set("env/wimpy", 100);   
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[6][100]=
	{
		"战利品是很多人梦寐以求的。",
		"大侠和大魔头都要杀很多人，只是杀的人不同一些。",
		"大侠多是口是心非之徒",
		"我不相信有什么真正的侠之大。",
		"如果在江湖中你还没杀过人，那，太惨了。",
		"什么，你经常被PK？恭喜你！！"
	};
	static char hua2[2][100]=
	{
		"有什么就快说，我比较忙。",
		"你有什么事？"
	};
	static char hua3[7][100]=
	{
		"我想做小偷。",
		"我只想平平淡淡。",
		"做一个世人敬仰的大侠是我的心愿。",
		"帮我杀一个人好吗？",
		"我丢了钱。",
		"你很漂亮。",
		"怎么对付比我厉害的人？"
	};
	static char hua4[7][100]=
	{
		"哈哈，有志气，那你可以入丐帮啊。。",
		"滚。。。。。。。",
		"是的，我也看出来了，阁下真是死人敬仰，嘿嘿嘿嘿。。。佩服佩服。",
		"好啊，不过你要先答应我的一个条件，那就是要你的一只手做为奖赏。",
		"丢了不要紧，可以偷的嘛，哈哈。",
		"是的，是比你要漂亮一点。",
		"只要出钱，什么事情都很容易解决。在江湖中，杀手是很多的，不过他们要价一般都比较高。"
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
		for(int ii=0;ii<7;ii++)
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

