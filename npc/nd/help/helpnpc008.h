//helpnpc008.h
//辛弃疾
//George 2001-07-07

NPC_BEGIN(CNhelpnpc008);

void create()
{
	set_name("辛弃疾", "xinqiji");

	set("title","文学家");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 45);
	set("long","手中握着一本书，不知他又想到了什么事");
	set("attitude", "friendly");  
	set("env/wimpy", 100);  
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"少年不识愁滋味，爱上层楼，爱上层楼。。。",
		"读书可以学习很多知识，当然也可以学武了。",
		"好的武功没有书籍帮助是不可能练成的。",
		"有很多书我要一本一本地读完它。",
		"今天又读了一本书，受益非浅。"
	};
	static char hua2[2][100]=
	{
		"你想了解什么书？",
		"我可以告诉你一些书的作用。"
	};
	static char hua3[82][100]=
	{

		"紫霞密芨",
		"十八木偶 ",
		"正气吟 ",
		"十八泥偶",
		"天山折梅手法图上卷 ",
		"天山折梅手法图下卷",
		"昊天掌法谱 ",
		"玉女心经上册 ",
		"玉女心经下册",
		"玉女剑谱",									//10

		"易筋经",
		"易经系辞篇",
		"易经杂卦篇",
		"易经说卦篇",
		"易经序卦篇",
		"旋风扫叶腿法 ",
		"洗髓经 ",
		"韦陀棍法 ",
		"龙爪功法 ",
		"风云手手法 ",									//20

		"天山器法 ",
		"华山剑谱2 ",
		"华山剑谱1 ",
		"一阳指诀",
		"掌法总谱 ",
		"杖法通解 ",
		"羊皮书 ",
		"六脉神剑谱",
		"神龙八式手法 ",
		"拳谱总诀 ",									//30		

		"黄石谱 ",
		"天羽奇剑剑谱 ",
		"羊皮 ",
		"辟邪剑谱 ",
		"招架入门 ",
		"密宗心经 ",
		"妙手空空入门秘籍",
		"独孤九剑剑谱",
		"天山六阳掌法图下册 ",
		"天山六阳掌法图上册 ",								//40

		"六脉神剑谱 ",
		"论语",
		"千字文",
		"百家姓",
		"三字经 ",
		"道德经「第八章」 ",
		"道德经「第二章」 ",
		"道德经「第十八章」 ",
		"道德经「第十六章」 ",
		"道德经「第十三章」 ",							//50

		"道德经「第一章」 ",
		"《葵花宝典》简体中文版 ",
		"「九阴真经」下册 ",
		"「九阴真经」上册 ",
		"「九阳真经」第四卷 ",
		"「九阳真经」第三卷 ",
		"「九阳真经」第二卷 ",
		"「九阳真经」第一卷 ",
		"金雁图谱 ",
		"「金蛇秘芨」下册 ",						//60

		"「金蛇秘芨」中册 ",
		"「金蛇秘芨」上册 ",
		"天涯寒月牌 ",
		"棋谱 ",
		"太极十三势 ",
		"『星宿毒经下册』",
		"『星宿毒经上册』 ",
		"轻功篇 ",
		"道德经「下卷」 ",
		"道德经「上卷」 ",								//70

		"道德经",
		"旧竹片 ",
		"石板 ",
		"薄绢 ",
		"易筋经文学篇 ",
		"铁手掌 ",
		"帛卷 ",
		"胡家刀谱残篇 ",
		"「洛书」 ",
		"「河图」 "	,										//80

		"一阳指法谱 ",
		"意形步法 " 													//82
	};
	static char hua4[82][100]=
	{
		"紫霞神功 0-99",
		"基本内功 60-99",
		"正气决  0-99  ",
		"基本内功 30-59 ",
		"天山折梅手  0-49 ",
		"天山折梅手  100-149 ",
		"昊天掌  0-80  ",
		"玉女心法  0-60 ",
		"玉女心法  0-100  ",
		"玉女剑法  0-40  ",
		
		"易筋经  0-200  ",
		"奇门五行  75-100 ",
		"奇门五行  50-75 ",
		"奇门五行  25-50 ",
		"奇门五行  0-25 ",
		"旋风扫叶腿  30-99 1000 ",
		"基本鞭法，基本指法，基本手法，基本杖法，基本爪法，基本掌法 0-180",
		"醉棍棍法 无常杖法 普渡杖法 伏魔剑法 达摩剑法  0-99 ",
		"鹰爪功法 拈花指法 一指禅功 慈悲刀法 修罗刀法  0-99 ",
		"如来千叶手手法 大金刚拳法 罗汉拳法 般若掌法 散花掌法  0-99 ",

		"飞星术  0-99  ",
		"基本剑法  101-199 ",
		"基本剑法  1-100 ",
		"一阳指  0-99 ",
		"基本掌法  0-30 ",
		"基本杖法  30-99 ",
		"基本剑法  100-149 ",
		"六脉神剑  0-99 ",
		"神龙八式  0-60 ",
		"基本拳脚  50-99 ",

		"五韵七弦剑  0-80 ",
		"天羽奇剑  50-150 ",
		"乾坤大挪移  0-250 （100读书,max_mp>1500 九阳神功要有同等级别）",
		"辟邪剑法  0-100  ",
		"基本招架  0-19  ",
		"密宗心法  0-99 ",
		"偷窃之术  0-20  ",
		"独孤九剑  75-300 （100读书） ",
		"天山六阳掌  100-149 ",
		"天山六阳掌  10-49  ",

		"六脉神剑  0-100 ",
		"读书写字  110-120 ",
		"读书写字  80-99  ",
		"读书写字  50-79  ",
		"读书写字  20-49 ",
		"道学心法  0-29 ",
		"道学心法  0-29 ",
		"道学心法  0-29 ",
		"道学心法  0-29 ",
		"道学心法  0-29 ",

		"道学心法  0-29 ",
		"辟邪剑法  0-200 ",
		"九阴白骨爪  0-99 ",
		"基本内功  100-199  ",
		"九阳神功  75-100 ",
		"九阳神功  50-75 ",
		"九阳神功  25-50 ",
		"九阳神功  0-25 500 ",
		"金雁功  0-60 ",
		"金蛇游身掌  0-200 ",

		"金蛇锥  0-200 ",
		"金蛇剑  0-200 ",
		"读书写字  基本拳脚  100-350 ",
		"基本手法  0-29 ",
		"基本内功  10-29 ",
		"基本毒技  99-199 ",
		"基本毒技  50-99 ",
		"基本轻功  0-100 ",
		"道学心法  0-99 ",
		"道学心法  0-49 ",

		"道学心法  0-99 ",
		"基本轻功  0-29 ",
		"基本指法  基本爪法  基本掌法  基本杖法  基本手法  0-29 ",
		"基本内功  0-29 ",
		"读书写字  10-19 ",
		"基本招架  0-29 ",
		"北冥神功  0-100 ",
		"基本刀法  30-99 ",
		"阴阳八卦  100-149 ",
		"阴阳八卦  40-69 ",

		"一阳指  0-150",
		"意形步法  0-60 "
	};
	char xingbie[10];
	int myage=0;
	int mylevel=0;
	myage=me->query("age");
	mylevel=me->query("level");
	if(!strlen(ask))
	{
		char msg1[50];
		strcpy(xingbie,me->querystr("gender"));
		if(strcmp(xingbie,"女性")==0)
			strcpy(msg1,"小姐，你受伤了，需要帮忙吗？");
		else if(strcmp(xingbie,"男性")==0)
			strcpy(msg1,"小兄弟,你受伤了，需要帮忙吗？");
		else
			strcpy(msg1,"小公公,你受伤了，需要帮忙吗？");
		if(random(2))
			return 0;
		for(int i=0;i<5;i++)
		{
			if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<82;ii++)
		{
			if(!random(10))
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
		case 26:return "26";
		case 27:return "27";
		case 28:return "28";
		case 29:return "29";
		case 30:return "30";
		case 31:return "31";
		case 32:return "32";
		case 33:return "33";
		case 34:return "34";
		case 35:return "35";
		case 36:return "36";
		case 37:return "37";
		case 38:return "38";
		case 39:return "39";
		case 40:return "40";
		case 41:return "41";
		case 42:return "42";
		case 43:return "43";
		case 44:return "44";
		case 45:return "45";
		case 46:return "46";
		case 47:return "47";
		case 48:return "48";
		case 49:return "49";
		case 50:return "50";
		case 51:return "51";
		case 52:return "52";
		case 53:return "53";
		case 54:return "54";
		case 55:return "55";
		case 56:return "56";
		case 57:return "57";
		case 58:return "58";
		case 59:return "59";
		case 60:return "60";
		case 61:return "61";
		case 62:return "62";
		case 63:return "63";
		case 64:return "64";
		case 65:return "65";
		case 66:return "66";
		case 67:return "67";
		case 68:return "68";
		case 69:return "69";
		case 70:return "70";
		case 71:return "71";
		case 72:return "72";
		case 73:return "73";
		case 74:return "74";
		case 75:return "75";
		case 76:return "76";
		case 77:return "77";
		case 78:return "78";
		case 79:return "79";
		case 80:return "80";
		case 81:return "81";
		case 82:return "82";
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
   else if(strcmp(y,"26")==0)
	   return 26;
   else if(strcmp(y,"27")==0)
	   return 27;
   else if(strcmp(y,"28")==0)
	   return 28;
   else if(strcmp(y,"29")==0)
	   return 29;
   else if(strcmp(y,"30")==0)
	   return 30;
   else if(strcmp(y,"31")==0)
	   return 31;
   else if(strcmp(y,"32")==0)
	   return 32;
   else if(strcmp(y,"33")==0)
	   return 33;
   else if(strcmp(y,"34")==0)
	   return 34;
   else if(strcmp(y,"35")==0)
	   return 35;
   else if(strcmp(y,"36")==0)
	   return 36;
   else if(strcmp(y,"37")==0)
	   return 37;
   else if(strcmp(y,"38")==0)
	   return 38;
   else if(strcmp(y,"39")==0)
	   return 39;
   else if(strcmp(y,"40")==0)
	   return 40;
   else if(strcmp(y,"41")==0)
	   return 41;
   else if(strcmp(y,"42")==0)
	   return 42;
   else if(strcmp(y,"43")==0)
	   return 43;
   else if(strcmp(y,"44")==0)
	   return 44;
   else if(strcmp(y,"45")==0)
	   return 45;
   else if(strcmp(y,"46")==0)
	   return 46;
   else if(strcmp(y,"47")==0)
	   return 47;
   else if(strcmp(y,"48")==0)
	   return 48;
   else if(strcmp(y,"49")==0)
	   return 49;
   else if(strcmp(y,"50")==0)
	   return 50;
   else if(strcmp(y,"51")==0)
	   return 51;
   else if(strcmp(y,"52")==0)
	   return 52;
   else if(strcmp(y,"53")==0)
	   return 53;
   else if(strcmp(y,"54")==0)
	   return 54;
   else if(strcmp(y,"55")==0)
	   return 55;
   else if(strcmp(y,"56")==0)
	   return 56;
   else if(strcmp(y,"57")==0)
	   return 57;
   else if(strcmp(y,"58")==0)
	   return 58;
   else if(strcmp(y,"59")==0)
	   return 59;
   else if(strcmp(y,"60")==0)
	   return 60;
   else if(strcmp(y,"61")==0)
	   return 61;
   else if(strcmp(y,"62")==0)
	   return 62;
   else if(strcmp(y,"63")==0)
	   return 63;
   else if(strcmp(y,"64")==0)
	   return 64;
   else if(strcmp(y,"65")==0)
	   return 65;
   else if(strcmp(y,"66")==0)
	   return 66;
   else if(strcmp(y,"67")==0)
	   return 67;
   else if(strcmp(y,"68")==0)
	   return 68;
   else if(strcmp(y,"69")==0)
	   return 69;
   else if(strcmp(y,"70")==0)
	   return 70;
   else if(strcmp(y,"71")==0)
	   return 71;
   else if(strcmp(y,"72")==0)
	   return 72;
   else if(strcmp(y,"73")==0)
	   return 73;
   else if(strcmp(y,"74")==0)
	   return 74;
   else if(strcmp(y,"75")==0)
	   return 75;
   else if(strcmp(y,"76")==0)
	   return 76;
   else if(strcmp(y,"77")==0)
	   return 77;
   else if(strcmp(y,"78")==0)
	   return 78;
   else if(strcmp(y,"79")==0)
	   return 79;
   else if(strcmp(y,"80")==0)
	   return 80;
   else if(strcmp(y,"81")==0)
	   return 81;
   else if(strcmp(y,"82")==0)
	   return 82;
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

