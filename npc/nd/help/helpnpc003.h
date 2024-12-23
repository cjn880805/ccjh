//helpnpc003.h
//丙冰花
//George 2001-07-07

NPC_BEGIN(CNhelpnpc003);

void create()
{
	set_name("丙冰花", "bingbinghua");
	set("title","花仙");

	set("icon", girl1);
	set("gender", "女性" );
	set("age", 15);
	set("long","头戴一朵金花。");
	set("attitude", "friendly");  
	set("env/wimpy", 100);
	set("no_talk",1);
} 
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[10][100]=
	{
		"在高手眼里，什么都可以做为暗器。",
		"暗器非常可怕。",
		"我只是知道，但自己并不会使用暗器。",
		"要非常小心敌人使用暗器，有些暗器是没有解药的。",
		"有一次采花的时候中了毒，原来武林中有很多人把这种花做为暗器。",
		"有很多大侠坚决不使用暗器，但很多大侠被暗器伤害了却没有办法。",
		"有一些暗器，人中了以后，生不如死。",
		"今天遇到一个中了暗器的侠客，还好，有朋友送来了解药。否则。。。。。。。",
		"我师傅就是被暗器所伤害，我一定会帮她报仇的。",
		"现在用暗器的人还是很多，不知道什么时候才是尽头。"
	};
	static char hua2[5][100]=
	{
		"我知道几种暗器，可以告诉你。",
		"你如果不明白，可以问我。",
		"暗器有好多种，我知道的也不多，你可以问我以下的。",
		"我可以告诉你几种暗器，你自己要小心一些。",
		"有什么不明白的就说吧。"
	};
	static char hua3[7][100]=
	{
		"花瓣",
		"凤尾箭",
		"毒蒺藜",
		"子母飞针",
		"碧磷针",
		"金蛇锥",
		"炼心弹",
	};
	static char hua4[7][150]=
	{
		"路边的野花的花瓣，和茶叶一样都是武林中的绝世高手首选的暗器。 ",
		"当年成吉思汗最喜欢用的弓箭，射杀大雕无数，符合空气动力学原理，射程远，杀伤力强， ",
		"中国独有的暗器，四川唐门原创，长满尖刺的外形使人望而却步，上面还喂有剧毒，是让人一看就发毛的暗器。 ",
		"特殊构造的高科技暗器，在发射后还能爆破成无数细小小针，令人防不胜防。 ",
		"星宿派的著名暗器，上面喂有星宿抽髓毒，发作之时全身骨髓如沸如冰，苦不堪言，世上只有两种药可解，十分可恶。 ",
		"和金蛇剑同出一脉，上面虽然没有喂毒，但是锥身构造特殊，长满倒钩，中了以后治疗十分困难。也是武林中臭名远扬的暗器之一。",
		"星宿第一暗器，抽髓毒含量更多，更浓，使用更安全，是星宿的招牌货，据说有些绝世高手为了考验自己的忍耐能力，故意去中这种暗器…… "
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

