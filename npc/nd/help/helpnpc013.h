//helpnpc013.h
//唐寅
//George 2001-07-07

NPC_BEGIN(CNhelpnpc013);

void create()
{
	set_name("唐寅", "tangyin");
	set("title","才子");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 27);
	set("long","口中朗朗有词，一直读个不停。");
	set("attitude", "friendly");     
	set("env/wimpy", 100);   
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[6][100]=
	{
		"在江湖中交流最重要，朋友多，则可以得天下。",
		"我的朋友应该是最多的了。",
		"在江湖中讲话要格外注意。",
		"悄悄话千万不要乱说。",
		"造谣太多会露出马脚。",
		"向大侠求助要客气一点。"
	};
	static char hua2[2][100]=
	{
		"有什么问题吗？",
		"如果有什么不明白就问我。"
	};
	static char hua3[13][100]=
	{
		"为什么要有“新手频道”？",
		"“说”是指什么？",
		"“闲聊”是怎么回事？",
		"谣言？说来听听。",
		"私聊如何操作？",
		"我想了解“门派频道”",
		"如何添加朋友？",
		"我口才不好，怎么办？",
		"能收我为徒吗？",
		"我很钦佩你的文采。",

		"你会武功吗？",
		"能借我本书读吗？",
		"有没有听说哪里有武功秘籍啊？"
	};
	static char hua4[13][150]=
	{
		"每个频道的使用都有一个条件，为了新手的方便，特意设置了一个新手频道，明白了吧？也有很多人很愿意帮助新手的。",
		"让本场景的所有人都能看到你讲的话语，可以选定某人，也可以自言自语。",
		"让每个玩家都可以看到的话，可以利用它在江湖上做到一呼百应的效果。",
		"并不是所有的人都能造谣，造谣也需要内力，而且如果漏气，就会泄露自己的身份，所以造谣还是要小心一点。",
		"当然是只有两个人才能讲的悄悄话了。",
		"自己所在的门派才能见到的对话。",
		"如果知道对方的ID，可以单击人物框，会弹出一个对话框，然后输入对方的ID就可以快速添加到朋友中了。",
		"没关系，你可以选中右上角朋友选页，然后选择“表情”，就可以表达你的各种表情和动作了，不妨试一试。",
		"我现在还未决定收任何徒弟。。。",
		"哈哈。。。哈哈哈。。。。。。。。。。。",
		
		"懂一点。",
		"我这里不开书店。",
		"到处都是，看你的运气吧。"
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
		for(int ii=0;ii<13;ii++)
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

