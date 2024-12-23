//LingJiu_mishi.h
//Sample for room: 灵鹫缥缈峰后山密道3


ROOM_BEGIN(CRLingJiu_mishi);

virtual void create()			//Call it when Room Create
{
	set_name( "灵鹫后山石室");

	add_door("灵鹫后山密道3", "灵鹫后山密道3", "灵鹫后山石室");
	set("no_fight",1);
	set("long","" );

};

virtual int do_look(CChar * me)
{
	time_t t;	
	time(&t);
	char msg[255];
	int i,j,level,num;
	if(me->query("lj/endtime") && t < me->query("lj/endtime")||wizardp(me))
	{
		say("你观察石室,发现只见四壁岩石打磨得甚是光滑，石壁上刻满了无数径长尺许的圆圈，每个圈中都刻了各种各样的图形。", me);
		say("有的是人像，有的是兽形，有的是残缺不全的文字，更有些只是记号和线条。", me);
		say("圆圈旁注着“甲一”、“甲二”、“子一”、“子二”等数字，圆圈之数若不逾千，至少也有八九百个，一时却哪里看得周全？", me);
		static char wuxue[5][20]=
		{
			"dodge","strike","hand","finger","sword"
		};
		static char wuxue1[5][20]=
		{
			"基本躲闪","基本掌法","基本手法","基本指法","基本剑法"
		};
		if(!me->query_temp("lj/skill/num"))
		{
			int count=1+int(me->query("int")/10);
			if(count>4)
				count=4;
			me->set_temp("lj/skill/num",count);
			for(i=0;i<me->query_temp("lj/skill/num");i++)
			{
				level=random(110)+360;
				num=random(5);
				if(i)
				{
					for(j=0;j<i;j++)
					{
						if(num==me->query_temp(snprintf(msg, 255,"lj/skill/skill_num%d",j)))
						{
							num=random(5);
							j=-1;
						}
					}
				}
				if(level>me->query_skill(wuxue1[num],1) && level<450)
				{
					level=level+random(20);//确保参悟出来的技能高于玩家的技能
				}
				me->set_temp(snprintf(msg, 255,"lj/skill/skill_num%d",i),num);
				me->set_temp(snprintf(msg, 255,"lj/skill/skill_name%d",i),wuxue1[num]);
				me->set_temp(snprintf(msg, 255,"lj/skill/skill_level%d",i),level);
				me->set_temp(snprintf(msg, 255,"lj/skill/%d",num),level);
				AddMenuItem(snprintf(msg, 255,"%s   %d",wuxue1[num],level), snprintf(msg, 255,"$0ji_%s $1",wuxue[num]), me);
			}
		}
		else
		{
			for(i=0;i<me->query_temp("lj/skill/num");i++)
			{
				AddMenuItem(snprintf(msg, 255,"%s   %d",me->querystr_temp(snprintf(msg, 255,"lj/skill/skill_name%d",i)),me->query_temp(snprintf(msg, 255,"lj/skill/skill_level%d",i))), snprintf(msg, 255,"$0ji_%s $1",wuxue[me->query_temp(snprintf(msg, 255,"lj/skill/skill_num%d",i))]), me);
			}
		}
		SendMenu(me);
	}
	else
	{
		tell_object(me, "\n$HIR你似乎已经不能从石壁上再领悟出什么，只觉得头晕脑胀，摇摇欲坠，不能再支持下去。");
		tell_object(me, "$HIR颤颤悠悠中，你扶着石壁，慢慢走出石室。");
		me->del("lj/endtime");
		if(me->querymap_temp("lj"))
			me->delete_temp("lj");
		me->move(load_room("灵鹫花园"));
	}
	return 1;
}


int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	time_t t;
	time(&t);
	if(me->query("lj/endtime") && t < me->query("lj/endtime")||wizardp(me))
	{
/*		if(strcmp(comm, "ji_force") == 0 )
		{
			tell_object(me, "$HIR\n你定睛向石壁的东北处瞧去，只见壁上刻满了人的奇经八脉。\n");
			tell_object(me, "你忍不住按脉运功。。。。");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("参悟中");
			me->set_temp("lj/skill_name","force");
			me->set_temp("lj/skill_id","基本内功");
			me->set_temp("lj/skill_index",1);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/0"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
*/		if(strcmp(comm, "ji_dodge") == 0 )
		{
			tell_object(me, "$HIR\n你定睛向石壁的西北处瞧去，只见壁上所刻图形，似乎是匹骏马。");
			tell_object(me, "$HIR昂首奔行，脚下云气弥漫，便如是在天空飞行一般。");
			tell_object(me, "$HIR再细看马足下的云气，只见一团团云雾似乎在不断向前推涌，直如意欲破壁飞出。\n");
			tell_object(me, "你看得片刻，内息翻涌。。。");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("参悟中");
			me->set_temp("lj/skill_name","dodge");
			me->set_temp("lj/skill_id","基本躲闪");
			me->set_temp("lj/skill_index",2);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/0"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_strike") == 0 )
		{
			tell_object(me, "$HIR\n你定睛向石壁的西南处瞧去，只见壁上画了两人在对掌。");
			tell_object(me, "$HIR你初觉两人掌法平平无奇，看到后来势式连贯，刚进柔出步走八方。");
			tell_object(me, "$HIR掌化万千，纵横交错，变化莫测。\n");
			tell_object(me, "你看得如痴如醉，不知不觉间盘膝坐下，对壁冥思起来。。。");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("参悟中");
			me->set_temp("lj/skill_name","strike");
			me->set_temp("lj/skill_id","基本掌法");
			me->set_temp("lj/skill_index",3);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/1"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_hand") == 0 )
		{
			tell_object(me, "$HIR\n你定睛向石壁的上方处瞧去，只见壁上画满了不同形状的手。\n");
			tell_object(me, "你冥思半天，双手跟着壁上那些手掌的方向比划起来，手化游龙变幻无常。。。");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("参悟中");
			me->set_temp("lj/skill_name","hand");
			me->set_temp("lj/skill_id","基本手法");
			me->set_temp("lj/skill_index",4);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/2"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_finger") == 0 )
		{
			tell_object(me, "$HIR\n你定睛向石壁的西北处瞧去，只见壁上好一帖狂草将军令。");
			tell_object(me, "$HIR字走龙飞凤舞，你忽觉钩划之间竟如一路指法。\n");
			tell_object(me, "你看得如痴如醉，指化兰花，顺着钩划一路舞起。。。");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("参悟中");
			me->set_temp("lj/skill_name","finger");
			me->set_temp("lj/skill_id","基本指法");
			me->set_temp("lj/skill_index",5);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/3"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_sword") == 0 )
		{
			tell_object(me, "$HIR\n你定睛向石壁的东南处瞧去，只见壁上密密麻麻的刻满了字。");
			tell_object(me, "$HIR但见千百文字之中，有些笔划宛然便是一把长剑，共有二三十把。");
			tell_object(me, "$HIR这此剑形或横或直，或撇或捺，有的剑尖朝上，有的向下，有的斜起欲飞，有的横掠欲坠。\n");
			tell_object(me, "你看得痴了，不知不觉间随着石壁的图文比划了起来。。。");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("参悟中");
			me->set_temp("lj/skill_name","sword");
			me->set_temp("lj/skill_id","基本剑法");
			me->set_temp("lj/skill_index",6);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/4"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
	}
	else
	{
		tell_object(me, "\n$HIR你似乎已经不能从石壁上再领悟出什么，只觉得头晕脑胀，摇摇欲坠，不能再支持下去。");
		tell_object(me, "$HIR颤颤悠悠中，你扶着石壁，慢慢走出石室。。");
		me->del("lj/endtime");
		if(me->querymap_temp("lj"))
			me->delete_temp("lj");
		if(!me->query("lj/renwu10"))
			me->del("lj");
		me->move(load_room("灵鹫花园"));
	}
	return CRoom::handle_action(comm, me, arg, target);
}

static void wakeup(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	if(!me) return;

	me->delete_temp("block_msg/all");
	me->enable_player();

	while( (me->environment())->is_character() )
		me->move((me->environment())->environment());
	
	
	LONG need_points =  me->skill_need_points(me->querystr_temp("lj/skill_name"));
	LONG need_exp = 3*(need_points / me->learn_bonus() + 1);
	
	if(me->query_valid_exp() < need_exp)
	{
		tell_object(me, "\n$HIR猛然间，你觉得浑身热气越来越盛，从丹田中不断涌将上来，身上有无数气流奔突窜跃，难过之极。");
		tell_object(me, snprintf(msg, 255, "$HIR你明白到是自己的江湖阅历不够，无法再去领悟石壁上高深的武功，不由的叹了口气（学习%s还需%ld点经验）。\n", me->querystr_temp("lj/skill_id"), need_exp));
	}
	else if(me->query_skill(me->querystr_temp("lj/skill_name"),1)>=me->query_temp("lj/skill_level"))
	{
		tell_object(me, "\n$HIR猛然间，你只觉得一阵头昏脑胀，无法定下心来去继续参悟着石壁上的这门高深武功。");
		tell_object(me, "$HIR你明白到是自己的武功修行今天已经暂时无法突破上限了，不由的叹了口气。");
	}
	else
	{
		me->set_skill(me->querystr_temp("lj/skill_name"),me->query_skill(me->querystr_temp("lj/skill_name"),1)+1);
		switch(me->query_temp("lj/skill_index"))
		{
/*		case 1:
			tell_object(me,"$HIR\n你在冥想中，忽然觉得经脉里有阵阵内息窜动，流动方向竟和那石壁上所刻画的图文一致。");
			tell_object(me,"$HIR顷刻间又归纳回丹田，原来你的内力已在不知不觉间增强了。");
			break;
*/		case 2:
			tell_object(me,"$HIR\n你在冥想中，忽然觉得盘膝而坐的两腿中似有经脉鼓胀之感。");
			tell_object(me,"$HIR一股走阳蹻脉，起于左脚跟中，循外踝上行，入风池，另一股起于右脚跟中，循内踝上行，至咽喉，交贯冲脉。");
			break;
		case 3:
			tell_object(me,"$HIR\n你在冥想中，忽然觉得摊放双膝上的两掌中，手厥阴心包经脉天泉、曲泽、郄门、间使、内关、大陵、劳宫、中冲等穴位......");
			tell_object(me,"$HIR手少阴心经脉的极泉、青灵、少海、灵道、通里、阴郄、神门、少府、少冲诸穴位......");
			tell_object(me,"$HIR都有些须儿发痛，并且一时间掌心热痛，好在没过多久这种感觉就消失了。");
			break;
		case 4:
			tell_object(me,"$HIR\n你一路演练下去，整个石室被你的手风所笼罩。");
			break;
		case 5:
			tell_object(me,"$HIR\n突然你心领神会嗤的一声，内力激射而出，指风直透墙而入。");
			break;
		case 6:
			tell_object(me,"$HIR\n你在冥想中，眼中突放晶芒，左手自鞘中拔出长剑舞了起来，顿时室内剑气横溢，盏茶之后方才收剑。");
			break;
		}
		tell_object(me, snprintf(msg, 255,"$HIR\n你凭借你丰富的江湖经验(-%d)，对%s的领悟又深了一层。\n",need_exp,me->querystr_temp("lj/skill_id")));
		me->add("combat_exp",-need_exp);
	}
	me->delete_temp("lj/skill_name");
	me->delete_temp("lj/skill_id");
	me->delete_temp("lj/skill_index");
	me->delete_temp("lj/skill_level");
	me->FlushMySkill(me);
	me->UpdateMe();
}


ROOM_END;
