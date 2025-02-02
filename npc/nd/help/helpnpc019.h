//helpnpc019.h
//申沉
//George 2001-07-07

NPC_BEGIN(CNhelpnpc019);

void create()
{
	set_name("申沉", "shencheng");
	
	set("title","武学专家");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 47);
	set("long","笔直地站在那个地方。");
	set("attitude", "friendly"); 
	set("env/wimpy", 100);     
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[17][300]=
	{
		"蛇形刁手、灵蛇杖法、蟾蜍步法、蛤蟆功是白驼山武功的基本武功，想要学会它却也不难。",
		"峨嵋的武功不过如此，回风七绝、回风拂柳剑、雁行刀法、大乘涅盘功、临济十二庄、诸天化身步、九阴白骨爪、金顶绵掌、天罡指穴法、渡世济人，有几种根本不堪一击，徒有虚名，你不要怕。",
		"玉女心经、玉女心法、玉女剑、玉女身法、银索金铃、纤云步法、天罗地网势、玄铁重剑式、狂潮心法、驱蜂之术、美女拳、黯然消魂掌、双手互搏、三无三不手、五毒神掌、五毒心法有一些厉害，不过还是有些柔软，没办法，古墓的武功根基本来就不高。",
		"灵鹫宫武功天生就乱七八糟的，不学也罢。八荒六合唯我独尊功、月影舞步、天羽奇剑、六阳掌、天山折梅手都是一看就让人怀疑的。门人中也多是俗手。",
		"全真武功太讲究名气了，一看它们的名字就知道了，什么先天气功、先天神功、全真剑、全真剑法、金雁功、昊天掌、一点也经不起推敲的功夫。",
		"神龙教是最毒的武功，学习多了会使人容易走火入魔，意形步法、神龙心法、神龙八式、蛇岛奇功、化骨绵掌现在已经很少有人练习了。",
		"你只要去过桃花岛，就会知道为什么那里人比较少了。玉萧剑法、旋风扫叶腿、弹指神通、奇门五行、落英神掌、落英神剑、兰花拂穴手、碧波神功、暗影浮香我都见识过，不过如此。",
		"武当功夫明明不厉害，却偏说是以柔克刚，很好笑。梯云纵、太极神功、太极拳、太极剑、太极刀、两仪剑法，一看就不是什么厉害的功夫",
		"少林武功据说不错，但要求太高，能练成的人很少,少林醉棍、一指禅、鹰爪功、易筋经神功、修罗刀、无影剑、无常杖法、韦陀棍、少林身法、散花掌、日月鞭法、如来千叶手、普渡杖法、拈花指、满天星、罗汉拳、龙爪功、大金刚拳、混元一气功、伏魔剑、风云手、达摩剑、慈悲刀、般若掌，太多了。。。",
		"雪山的功夫没见识过，用的人也不多，可能现在还有金刚瑜迦母拳、血刀心法、血刀、小无相功、身空行、日月轮法、密宗心法、明王剑、龙象般若功、火焰刀、密宗大手印、金刚降魔杵，其它大多已经失传了。。。。",

		"逍遥的功夫有逍遥剑法、逍遥刀法、北冥神功、凌波微步、凌霄快剑，因为找不到传人正四处招徒弟呢，你是不是想去？",
		"星宿功夫摘星功、星宿毒掌、天山杖法、三阴蜈蚣抓、化功大法、飞星术、抽髓掌、基本毒功因为大多为武林人士所不齿，所以又叫“下三滥功夫”。",
		"华山武功紫霞神功、华山剑法、玉女金针十三剑、狂风快剑、反两仪刀法、华山身法、飞燕回翔、独孤九剑、劈石破玉拳、混元掌、正气决因为剑宗和气宗的矛盾一直存在，所以到底哪个厉害，他们自己都不知道，我也弄不明白。",
		"丐帮武功逍遥游、降龙十八掌、混天气功、打狗棒、乞讨术、偷窃术本来也不错，但现在大部分丰丐帮的只会练习乞讨术，深为武林所憎恨。",
		"明教武功风雷刀、巫月刀法、五韵七弦剑、明王剑、石鼓打穴笔法、轩辕箭、夺命银花、圣火令法、鹰爪手、搜骨鹰爪功、烈焰寒冰掌、寒冰绵掌、猴拳、玄天无情指、圣火心法、圣火神功、九阳神功、玄天神功、乾坤大挪移、飘逸步法、青蝠身法需要的先天造诣太高，教主好象就是因为练功窒息而死的。",
		"段氏武功一阳指、正品一阳指、五罗轻烟掌、金玉拳、飞凤鞭法、段家剑、天南步法、轻蝶身法、天龙神功、枯荣神功、枯荣禅功、六脉神剑是至阳的功夫，如果用功练习，必成气候，只可惜段氏中人大多拈花惹草，对武学反而落后了不少。",
		"江湖上还有一个日月神教，要自宫后才可以练习，这个我还没试过。"
	};
	static char hua2[2][100]=
	{
		"我还知道一些绝技，你想了解哪一个？",
		"还有一些独门绝技，你可以问我。"
	};
	static char hua3[16][100]=
	{

		"白驼山绝技",
		"峨嵋绝技",
		"古墓绝技",
		"灵鹫宫绝技",
		"全真绝技",
		"神龙教绝技",
		"桃花岛绝技",
		"武当绝技",
		"少林绝技",
		"雪山绝技",

		"逍遥绝技",
		"星宿绝技",
		"华山绝技",
		"丐帮绝技",
		"明教绝技",
		"段氏绝技"
	};
	static char hua4[16][250]=
	{

		"雷霆霹雳（灵蛇杖法）",
		"灭剑（回风拂柳剑）、情天难补（回风七绝）、无形幻影（雁行刀法）、凌空指穴（天罡指穴法）、八式合一（金顶绵掌）、亡魂一击（九阴白骨爪）、劝架（渡世济人）",
		"摄心术（玉女心经）、双剑合璧（玉女剑）、点穴、封穴（银索金铃）、奔潮诀（玄铁重剑式）、情却千里（狂潮心法）、古墓幽居（美女拳）、黯然消魂（黯然消魂掌）、解毒（五毒神掌）",
		"天女散花（天羽奇剑）、种生死符、解生死符（六阳掌）、空手入白刃（折梅手）、",
		"定阳针、沧澜一剑（全真剑）、三花聚顶（昊天掌）、一剑化三清、同归于尽（全真剑法）",
		"惊魂绝唱一、二、三段（蛇岛奇功）、辣手化骨（化骨绵掌）、",
		"势合形离（玉萧剑法）、狂风绝技（旋风扫叶腿）、挥斥方遒、弹指惊雷（弹指神通）、奇门遁甲（奇门五行）、玄字诀（落英神掌）、拈花拂穴（兰花拂穴手）、",
		"神功震敌（太极拳）、随字诀、连字诀、缠字诀（太极剑）、天地同仁（两仪剑法）、",
		"八仙醉打（少林醉棍）、点字决、惊魔一指（一指禅）、佛门狮子吼（易筋经神功）、分身无影（无影剑）、缠绕诀（日月鞭法）、拈花拂穴（拈花指）、佛云以杀止杀（罗汉拳）、大金刚神通（大金刚拳）、佛门狮子吼（混元一气功）、达摩三绝剑（达摩剑）、",
		"祭血神刀（血刀）、金钟罩（小无相功）、梵唱（龙象般若功）、焚心以火（火焰刀）、",

		"凌霄十三剑（凌霄快剑）、化功大法、吸功术（北冥神功）",
		"施毒术（星宿毒掌）、膻中吸功、天灵吸功、空手吸气、吸气术（化功大法）、满天花雨（飞星术）、散毒术、施毒术（抽髓掌）、",
		"总诀式、破刀式、破枪式、破剑式、破鞭式、破索式、破箭式、破掌式、破气式（独孤九剑）、剑掌五连环（华山剑法）、无双无对（玉女金针十三剑）、天外飞龙（狂风快剑）、华岳三神峰（反两仪刀法）、混元无极（混元掌）、雷动九天（劈石破玉拳）",
		"雷霆一击、降龙大法（降龙十八掌）、千环套狗（打狗棒）、乞讨（乞讨术）、偷窃（偷窃术）",
		"铰字诀（巫月刀法）、满天花雨（夺命银花）、夺焰令、吸焰令（圣火令法）、牧野鹰扬（搜骨鹰爪功）、震字诀（猴拳）、吸血青蝠（寒冰绵掌）、长啸（玄天神功）、",
		"惊天一击（段家剑）、一指乾坤（正品一阳指）、刺字、封字、弹字诀（六脉神剑）"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<17;i++)
		{
			if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<16;ii++)
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

