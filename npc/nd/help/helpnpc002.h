//helpnpc002.h
//太乙假人
//George 2001-07-07

NPC_BEGIN(CNhelpnpc002);

void create()
{
	set_name("太乙假人", "taiyijiaren");
	set("title","发明家");
	
	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 70);
	set("long","长胡须老者。");
	set("attitude", "friendly"); 
	set("env/wimpy", 100);  
	set("no_talk",1);
}  
int do_talk(CChar * me, char * ask = NULL)
{
	
	static char hua1[18][100]=
	{
		"不论想要做什么，用我的纸人一定行的",
			"我最近正在研究一种新的纸人。",
			"造纸人的关键秘密我是不会乱说的。",
			"你不要问我有多少钱，只要知道我的纸人好用就可以了。",
			"我的纸人定价明确，老少不欺。",
			"我这里不卖纸人，有很多地方都出售纸人。",
			"有位大侠说要帮我找一种原材料，至今都没找到。",
			"我做了一种纸人，很厉害，不过现在还不能说。",
			"为什么每天有那么多的人用我的纸人？你问他们就知道了。",
			"现在的纸人唯一的不足之处就是只能让一个人使用。",
			
			"没有人不知道我的名字，不过他们知道的却不是我的真名。",
			"我为什么不做用来杀人的纸人，完全是因为我自己不想做它。",
			"我的住所很秘密，除了几个有交往的朋友知道，其他人都不知道。",
			"其实我的纸人还有很多秘密，只是一般人不太明白。。。",
			"我正在研究一种万能的纸人，不过可能不会出售。",
			"今天又有很多人来我这里收购了许多纸人。",
			"木偶人由于材料不容易找，所以一般做的时间比较长。",
			"新的铁人就要做出来了，还缺乏一种石头，不知道什么时候才能找到。",
	};
	static char hua2[8][100]=
	{
		"你好，你是不是有什么疑问？",
			"有什么不明白的你可以直接问我。",
			"你还有什么不懂的？",
			"我可以回答你的一些问题。",
			"你还想知道什么？",
			"不用说了，你是不是还不明白？",
			"好了，你要问吗？",
			"如果不清楚，我可以说的详细一点。"
	};
	static char hua3[7][100]=
	{
		"纸偶人",
			"纸咒人",
			"纸符人",
			"木偶人",
			"铁人",
			"万能纸人",
			"什么地方能用纸人啊？"
	};
	static char hua4[7][100]=
	{
		"可以用它来提高自己的内力。",
			"可用来自动练习技法。",
			"读书时必备的物品。",
			"如果有一个自己的木偶人，就可以天天练功了，进步很快。",
			"我正在研究。。。。",
			"快要生产出来了，你等着吧。",
			"既能休息也能练功的地方，家是最好的地方，其它能战斗的地方都比较危险。"	
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<18;i++)
		{
			if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(8)],me);
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

