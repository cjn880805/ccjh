//helpnpc006.h
//妲己
//George 2001-07-07

NPC_BEGIN(CNhelpnpc006);

void create()
{
	set_name("妲己", "daji");
	set("title","爱涂爱抹");

	set("icon", girl1);
	set("gender", "女性" );
	set("age", 19);
	set("long","美人");
	set("attitude", "friendly");   
	set("env/wimpy", 100);  
	set("no_talk",1);
} 
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"在战斗中，食物和道具可以起到很大的作用。",
		"有很多珍贵的物品都要努力寻找才会得到。",
		"常用药品和食品在很多地方都有售。",
		"有些大侠因为找不到解药而使中毒加深。",
		"一定要了解一些药物和食品的作用才能在江湖中闯荡。"
	};
	static char hua2[2][100]=
	{
		"你还要了解什么？",
		"还可以告诉你一些。"
	};
	static char hua3[33][100]=
	{
		"粽子",
		"羊肉串",
		"清心散",
		"雪莲",
		"翔少爷",
		"阴阳合和散",
		"天香断续膏",
		"蛇胆糕",
		"老山叁",
		"三笑逍遥散",

		"蒙汗药",
		"火星人",
		"烤鸭",
		"蛋糕",
		"竹叶青",
		"烤鸡腿",
		"静心口服液",
		"黑玉断续膏",
		"白云熊胆丸",
		"冰雪翡翠糕",
		
		"药粉",
		"金创药",
		"雪参玉蟾丹",
		"朱睛冰蟾",
		"百香花",
		"时空传送帖",
		"回程卷轴",
		"封印魔法",
		"同心印",
		"原始铁胚",
		
		"七色七音盒",
		"面具",
		"江湖补给包"

	};
	static char hua4[33][200]=
	{
		"香喷喷的肉粽子，包它的粽子叶泛出一股清香，味道不错，可以试试。",
		"香喷喷的羊肉串，上面沾满了孜然和辣椒面，你如果怕辣千万别吃它。",
		"星宿毒的解药",
		"效果非常好，可以快速疗伤。",
		"这是助长内力的灵药，吃了之后有要飞翔的欲望，像个少爷似的。据说可以永久增大内力。",
		"一种强烈的春药。如果你误食，哈哈。。。。。。",
		"这是一盒黑色的疗伤膏药，可以擦涂（smear）",
		"这是珍贵补品『蛇胆膏』。小辈吃了加最大HP",
		"长白有很多老山叁。也是疗伤良药。",
		"是一种无色的粉末, 你看它的样子就知道不是寻常物品. 星宿的三笑毒",
		
		"使人昏睡的一种药品。很多有钱人家的花花公子经常随身携带",
		"火星人可以作为地球人的食品。",
		"普通食品，吃过就知道了。",
		"结婚时朋友送的食品，味道很好。",
		"喜酒，要小心饮用，非常容易醉人。",
		"小吃，很多人都很爱吃。",
		"女人中年要静心，李清照入魔多年才悟出这个道理。可以解冰魄银针和五毒神掌的毒。",
		"极其难配制的的黑玉断续膏,据说能起死回生。",
		"武林人士梦寐以求的疗伤圣药。",
		"吃了以后会引人食欲大增。",
		
		"专治内伤的药粉。只有专练可对付‘化骨绵掌’的武功的人才需要服这种药。",
		"最流行的疗伤药，就是价钱贵了一点。",
		"能解九十九种毒的灵药，也许是因为目前用毒的人不多，所以价格不贵，在各大药店均有销售。",
		"能解百毒的灵药，就是不那么容易找到。",
		"加最大MP 5点",
		"从妖魔身上夺下的东西，可以穿梭空间，在北京，扬州，白驼，星宿，大理，泉州等地自由来往。",
		"从西洋进口的好东西，可以马上逃到安全的地方，例如你的家或者你最近存过盘的客栈。好而不贵，真正实惠",
		"同样是进口货,可以将一个箱子封住，一般的人打不开。也可以用这东西解开封印。",
		"男人使用后，女人使用，就结婚喽！不能离婚喽！",
		"铸造兵器的原材料，在佛山购买后到泉州青龙会给凶猛的狗，然后和他商量具体要求，他就会帮你打造随身携带的兵器，这兵器会随战斗成长。",
		
		"找某些东西用的东西。",
		"神奇的变形面具，对某人使用之后就可以把面具画成他的样子，戴上以后干尽坏事也没人认得你，",
		"由无良奸商萧半和售卖，价格奇高，其中捆绑销售一大堆食品药品，包括临时增加属性的药品，间或会有好东西，"
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
		for(int ii=0;ii<33;ii++)
		{
			if(!random(4))
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

