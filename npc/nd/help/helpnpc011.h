//helpnpc011.h
//小孙子
//George 2001-07-07

NPC_BEGIN(CNhelpnpc011);

void create()
{
	set_name("小孙子", "xiaosunzi");

	set("title","谋士");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 60);
	set("long","一边走一边哼着什么。。。");
	set("attitude", "friendly");   
	set("env/wimpy", 100); 
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[3][100]=
	{
		"做战和赚钱都很重要，你如何选择？",
		"技能和级别也都很重要，要安排合理才会厉害。",
		"一定要有最佳的安排，在江湖中才会出人头地。"
	};
	static char hua2[2][100]=
	{
		"是不是不明白？",
		"如果不明白可以问我。"
	};
	static char hua3[24][100]=
	{

		"如何赚钱？",
		"有能领工资的地方吗？",
		"你知道哪里有宝藏吗？",
		"有武功速成秘笈吗？",
		"做什么生意最容易发达？",
		"是不是必须战斗啊？",
		"是不是每次战斗都要决出胜负啊？",
		"战斗是如何进行的？",
		"MP是什么？",
		"什么是AP？",

		"战斗中是如何得经验的？",
		"我还是不太清楚什么是NK经验。",
		"有人总说PK谁，PK是什么？",
		"怎么我经验栏中有三个值啊？",
		"练功向谁请教？",
		"是不是一定要向师傅学习呢？",
		"高级内功怎么练习？",
		"为什么要学习高级内功？",
		"空手功夫有什么好处？",
		"内功是不是只能用来疗伤？",

		"技能是不是学得越多越好？",
		"攻击：100(+120)是什么意思？",
		"在战斗中受了伤怎么办？",
		"中了毒怎么办？"
	};
	static char hua4[24][250]=
	{

		"江湖上总有一些出手阔绰的人不在乎一些武器装备什么的，他们杀了NPC只要钱，不要装备。您运气好的话或许能拣到这些破烂，然后拿了卖。这也未尝不是条生财之道。",
		"我只知道有大理，成为武将后可以定期领工资，吃皇粮。",
		"知道，在一个遥远的地方。。。。。。",
		"很少，在江湖中资历特别重要，不过据说有的武功只要有机缘，还是可以迅速成名的。",
		"很多，可以开书店，兵器店，药店，既可以出租也可以发售，定价由自己决定，还有很多，你慢慢就会知道了。",
		"经验点是角色成长中最重要的一项指针。有了经验点，才能够使你的角色升级，才能学习更多的武艺。获得经验，战斗是最重要的一条途径。当然，我们学习更多的技能，也是为了在战斗中战胜更强大的敌人。",
		"战斗分两种，一种属于切磋，一种属于决斗。切磋武艺点到为止，一般不会丧命；决斗是非要分出个你死我活的，就算逃脱，下次见面仍会“仇人相间分外眼红”的！因此，找NPC战斗，可以先用切磋和他较量。如果你有把握杀死对方，可以直接对其下KILL指令，杀死对手。",
		"战斗是自动进行的。在战斗的过程中，你可以使用法术打击敌人。法术是要耗费MP和AP的。同时，在战斗中，无论你是使用物品还是装备武器，甚或是逃跑，都需要积累足够的AP值才能完成。",
		"MP指法力点数，通过打坐提高。前提是你必须具备了某种内功。使用法术要消耗一定的MP，造谣也要MP，有些魔法物品的使用也需要有足够的MP才行。因此，修炼MP是我们成长中一个很重要的过程。",
		"AP就是行动力点数，只在战斗中有效。每回合出手时自动累加，累加最大上限500。通常敏捷越高的人，在战斗中出手的速度越快，每回合AP增长的越多。",

		"在战斗的过程中，当你的防御低于对手的攻击，同时你又成功的招架或躲闪了过去，您就有机会获得少许经验。当然，如果你的攻击低于对手的防御，同时你又成功的命中了对手，那么您可获得稍高些的经验。",
		"如果你杀死的NPC经验值比你高，且不与你同门派，那么你将获得一定的经验奖励，此谓NK经验。",
		"PK经验就是杀死玩家获得的经验了。",
		"如：1001/2000 (465)则表示你可自由支配经验是1001，其中可以用于学技能的经验是465点。角色升级需要2000点。",
		"可向自己师父直接请教，也可转拜同派内其它师父，这个不算判师。",
		"如果某项基本技能你的师父不会，那么可以去成都金牛武馆付给帐房先生一定学费，从武馆师傅那里学习。",
		"高级内功一般是不能练习的，只能向师父请教。",
		"准备了高级内功后，就可打坐了。打坐是修炼MP的途径。",
		"一般空手功夫都可准备到基本拳脚上，在战斗时空手使用。有些空手功夫和另外的空手功夫组合，可发挥更大的威力。",
		"可以在战斗时用内力伤敌。想用内力伤人，需要在环境设置里设置加力系数。所谓加力系数就是你打算用几点内力伤敌。",

		"一个人不受限制的可以学习最多20种技能。超过20种技能后，每多一种，学习的难度增加10%。",
		"第一个数字是自己本身的攻击力，第二个数字是武器附加的攻击力。",
		"疗伤可以买金疮药来吃，也可以找其它老玩家帮助你。比如少林，明教，古墓，华山，娥眉的内功都有为人疗伤的法术。",
		"有些毒多睡一会就没事了，为了安全起见，还是吃一些药品比较好，每种毒的解法都不一样，比如如果中了生死符，那就麻烦了。"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<3;i++)
		{
		//	if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<24;ii++)
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

